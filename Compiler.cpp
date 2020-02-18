#include "Compiler.hpp"
#include "Exceptions.hpp"
using namespace std;

bool Compiler::AddCompileWord(CustomDefinition &d, const std::string &token) {
    if (token == "IF") AddIf(d);
    else if (token == "ELSE") AddElse(d);
    else if (token == "THEN") AddThen(d);
    else if (token == "BEGIN") AddBegin(d);
    else if (token == "REPEAT") AddRepeat(d);
    else if (token == "AGAIN") AddAgain(d);
    else if (token == "WHILE") AddWhile(d);
    else if (token == "DO") AddDo(d, false);
    else if (token == "?DO") AddDo(d, true);
    else if (token == "LOOP") AddLoop(d, false);
    else if (token == "+LOOP") AddLoop(d, true);
    else if (token == "LEAVE") AddLeave(d);
    else if (token == "UNLOOP") AddUnloop(d);
    else if (token == "I") AddIndex(d, true);
    else if (token == "J") AddIndex(d, false);
    else if (token == "RECURSE") AddRecurse(d);
    else if (token == ".\"") AddPrintStr(d);
    else if (token == "EXIT") AddExit(d);
    else return false;

    return true;
}

void Compiler::AddDefinition(DefDict &dict) {
    auto def = make_shared<CustomDefinition>();
    c.clear(); // may be non-empty from previous bad definition
    string name = t.GetToken();
    string token = t.GetToken();
    for (; !token.empty() && token != ";"; token = t.GetToken()) {
        if (token == "\n") continue;
        else if (dict.count(token))
            def->v.push_back(dict.at(token));
        else if (Tokenizer::IsNumeric(token)) {
            auto con = make_shared<Const>(Tokenizer::GetNum(token));
            def->v.push_back(move(con));
        }
        else if (!AddCompileWord(*def, token)) {
            throw UnknownWord();
        }
    }

    if (!c.empty()) throw BadDefinition(); // ensure all blocks are properly closed

    dict[name] = def;
}

// items on the control-flow stack are converted between ptrdiff_t and size_t
// (because we need negative stack values for loop-sys, but vector indices and IP are size_t)
// this is fine, since no one should really make definitions 2^31 (or even 2^63) words long

void Compiler::AddIf(CustomDefinition &d) {
    c.push(d.size()); // If's position is put on the stack to resolve the jump by Else/Then
    d.v.push_back(make_shared<If>());
}

void Compiler::AddElse(CustomDefinition &d) {
    auto i = static_cast<size_t>(c.top()); c.pop();
    size_t res = d.size();
    d.v.push_back(make_shared<Else>());
    d[i]->Compile(res); // resolve the If by giving it Else's position to jump to
    c.push(res); // Else's position is put on the stack to be resolved by Then
}

void Compiler::AddThen(CustomDefinition &d) {
    auto i = static_cast<size_t>(c.top()); c.pop();
    d[i]->Compile(d.size()); // resolve the If/Else, giving it Then's position to jump to
    d.v.push_back(make_shared<Then>());
}

void Compiler::AddBegin(CustomDefinition &d) {
    c.push(d.size()); // Begin's position, to be consumed by Repeat/Until
    d.v.push_back(make_shared<Begin>());
}

void Compiler::AddWhile(CustomDefinition &d) {
    auto dest = static_cast<size_t>(c.top()); c.pop();
    c.push(d.size()); // Add While's position under the position of Begin
    c.push(dest);
    d.v.push_back(make_shared<If>()); // While is functionally identical to If
}

void Compiler::AddRepeat(CustomDefinition &d) {
    auto dest = static_cast<size_t>(c.top()); c.pop(); // Begin's position
    auto orig = static_cast<size_t>(c.top()); c.pop(); // While's position
    size_t o_res = d.size();
    d[orig]->Compile(o_res); // Resolve While, giving it jump to Repeat
    d.v.push_back(make_shared<Repeat>());
    d[o_res]->Compile(dest); // Resolve the now added Repeat, giving it jump to Begin
}

void Compiler::AddAgain(CustomDefinition &d) {
    auto dest = static_cast<size_t>(c.top()); c.pop();
    // AGAIN run-time semantics are identical to REPEAT's
    d.v.push_back(make_shared<Repeat>());
    d.v.back()->Compile(dest);
}

void Compiler::AddDo(CustomDefinition &d, bool checked) {
    c.push(d.size());  // the loop-sys has the following format (from the bottom):
    c.push(-1);  //         (1) Do's position, (2) -1, (3) positions of related Leaves, (4) -1
    c.push(-1);
    if (checked)
        d.v.push_back(make_shared<CheckedDo>());
    else
        d.v.push_back(make_shared<Do>());
}

void Compiler::AddLoop(CustomDefinition &d, bool plus) {
    size_t res = d.size();
    c.pop(); // remove the enclosing -1 of loop-sys
    ptrdiff_t i = c.top(); c.pop();
    while (i != -1) {   // compile all Leaves with jumps after this Loop
        d[i]->Compile(res);
        i = c.top(); c.pop();
    }
    i = c.top(); c.pop(); // get Do's position
    if (plus)
        d.v.push_back(make_shared<PLoop>());
    else
        d.v.push_back(make_shared<Loop>());
    d[i]->Compile(res); // set up jump for possible "?DO"
    d[res]->Compile(static_cast<size_t>(i)); // set up (P)Loop's jump to Do's position
}

// LEAVE needs to find the nearest loop-sys, since it could be called e.g. inside an IF .. THEN
// block and simply putting its reference on top would pollute the stack
void Compiler::AddLeave(CustomDefinition &d) {
    Stack tmp;
    for (; c.top() != -1; c.pop()) // find the nearest loop-sys
        tmp.push(c.top());

    c.pop(); // remove the enclosing -1
    c.push(d.size()); // append Leave's position to loop-sys
    c.push(-1); // add the -1 back
    for (; !tmp.empty(); tmp.pop())
        c.push(tmp.top());

    d.v.push_back(make_shared<Leave>());
}

void Compiler::AddUnloop(CustomDefinition &d) {
    d.v.push_back(make_shared<Unloop>());
}

void Compiler::AddIndex(CustomDefinition &d, bool i) {
    if (i)
        d.v.push_back(make_shared<I>());
    else
        d.v.push_back(make_shared<J>());
}

void Compiler::AddPrintStr(CustomDefinition &d) {
    string text = t.GetUntil('"');
    d.v.push_back(make_shared<PrintStr>(text));
}

void Compiler::AddRecurse(CustomDefinition &d) {
    d.v.push_back(make_shared<Recurse>(d));
}

void Compiler::AddExit(CustomDefinition &d) {
    d.v.push_back(make_shared<Exit>(d));
}