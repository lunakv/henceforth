#include "Compiler.hpp"
#include "Exceptions.hpp"
using namespace std;

bool Compiler::AddCompileWord(CustomDefinition &d, const std::string &token) {
    if (token == "IF") AddIf(d);
    else if (token == "ELSE") AddElse(d);
    else if (token == "THEN") AddThen(d);
    else if (token == "BEGIN") AddBegin(d);
    else if (token == "REPEAT") AddRepeat(d);
    else if (token == "WHILE") AddWhile(d);
    else if (token == "DO") AddDo(d);
    else if (token == "LOOP") AddLoop(d, false);
    else if (token == "+LOOP") AddLoop(d, true);
    else if (token == "LEAVE") AddLeave(d);
    else if (token == "RECURSE") AddRecurse(d);
    else if (token == ".\"") AddPrintStr(d);
    else return false;

    return true;
}


void Compiler::AddDefinition(const DDRef &dict) {
    auto def = make_shared<CustomDefinition>();
    string name = t.GetToken();
    string token = t.GetToken();
    for (; !token.empty() && token != ";"; token = t.GetToken()) {
        if (token == "\n") continue;

        if (dict->count(token))
            def->v.push_back(dict->at(token));
        else if (Tokenizer::IsNumeric(token)) {
            auto con = make_shared<Const>(Tokenizer::GetNum(token));
            def->v.push_back(move(con));
        }
        else if (!AddCompileWord(*def, token)) {
            throw UnknownWord();
        }
    }

    (*dict)[name] = def;
}

void Compiler::AddIf(CustomDefinition &d) {
    c.push(d.size()); // If's position is put on the stack to resolve the jump by Else/Then
    d.v.push_back(make_shared<If>());
}

void Compiler::AddElse(CustomDefinition &d) {
    size_t i = c.top(); c.pop();
    size_t res = d.size();
    d.v.push_back(make_shared<Else>());
    d[i]->Compile(res); // resolve the If by giving it Else's position to jump to
    c.push(res); // Else's position is put on the stack to be resolved by Then
}

void Compiler::AddThen(CustomDefinition &d) {
    size_t i = c.top(); c.pop();
    d[i]->Compile(d.size()); // resolve the If/Else, giving it Then's position to jump to
    d.v.push_back(make_shared<Then>());
}

void Compiler::AddBegin(CustomDefinition &d) {
    c.push(d.size()); // Begin's position, to be consumed by Repeat/Until
    d.v.push_back(make_shared<Begin>());
}

void Compiler::AddWhile(CustomDefinition &d) {
    size_t dest = c.top(); c.pop();
    c.push(d.size()); // Add While's position under the position of Begin
    c.push(dest);
    d.v.push_back(make_shared<If>()); // While is functionally identical to If
}

void Compiler::AddRepeat(CustomDefinition &d) {
    size_t dest = c.top(); c.pop(); // Begin's position
    size_t orig = c.top(); c.pop(); // While's position
    size_t o_res = d.size();
    d[orig]->Compile(o_res); // Resolve While, giving it jump to Repeat
    d.v.push_back(make_shared<Repeat>());
    d[o_res]->Compile(dest); // Resolve the now added Repeat, giving it jump to Begin
}

void Compiler::AddDo(CustomDefinition &d) {
    c.push(d.size());  // the loop-sys has the following format (from the bottom):
    c.push(-1);  //         (1) Do's position, (2) -1, (3) positions of related Leaves, (4) -1
    c.push(-1);
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
    c.pop();  // remove the other enclosing -1
    i = c.top(); c.pop(); // get Do's position
    if (plus)
        d.v.push_back(make_shared<PLoop>());
    else
        d.v.push_back(make_shared<Loop>());
    d[res]->Compile(i); // set up (P)Loop's jump to Do's position
}

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

void Compiler::AddPrintStr(CustomDefinition &d) {
    string text = t.GetUntil('"');
    d.v.push_back(make_shared<PrintStr>(text));
}

void Compiler::AddRecurse(CustomDefinition &d) {
    d.v.push_back(make_shared<Recurse>(d));
}