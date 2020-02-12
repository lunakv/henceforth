#include "Compiler.hpp"
using namespace std;

Compiler::Compiler(Tokenizer &t) : t(t) {}

bool Compiler::AddCompileWord(std::vector<std::shared_ptr<Definition>> &v, const std::string &token) {
    size_t orig_size = v.size();
    if (token == "IF") AddIf(v);
    else if (token == "ELSE") AddElse(v);
    else if (token == "THEN") AddThen(v);
    else if (token == "BEGIN") AddBegin(v);
    else if (token == "REPEAT") AddRepeat(v);
    else if (token == "WHILE") AddWhile(v);
    else if (token == "DO") AddDo(v);
    else if (token == "LOOP") AddLoop(v, false);
    else if (token == "+LOOP") AddLoop(v, true);
    else if (token == "LEAVE") AddLeave(v);
    return v.size() != orig_size;
}


void Compiler::AddDefinition(const DDRef &d) {
    vector<shared_ptr<Definition>> v;
    string name = t.GetToken();
    string token = t.GetToken();
    for (; !token.empty() && token != ";"; token = t.GetToken()) {
        if (token == "\n") continue;

        if (d->count(token))
            v.push_back(d->at(token));
        else if (Tokenizer::IsNumeric(token)) {
            auto con = make_shared<Const>(Tokenizer::GetNum(token));
            v.push_back(con);
        }
        else if (!AddCompileWord(v, token)) {
            throw exception(); // Unknown token
        }
    }

    if (token.empty())
        throw exception(); // end of stream reached before end of definition

    (*d)[name] = make_shared<CustomDefinition>(std::move(v));
}

void Compiler::AddIf(vector<shared_ptr<Definition>> &v) {
    c.push(v.size()); // If's position is put on the stack to resolve the jump by Else/Then
    v.push_back(make_shared<If>());
}

void Compiler::AddElse(vector<shared_ptr<Definition>> &v) {
    size_t i = c.top(); c.pop();
    size_t res = v.size();
    v.push_back(make_shared<Else>());
    v[i]->Compile(res); // resolve the If by giving it Else's position to jump to
    c.push(res); // Else's position is put on the stack to be resolved by Then
}

void Compiler::AddThen(vector<shared_ptr<Definition>> &v) {
    size_t i = c.top(); c.pop();
    v[i]->Compile(v.size()); // resolve the If/Else, giving it Then's position to jump to
    v.push_back(make_shared<Then>());
}

void Compiler::AddBegin(vector<shared_ptr<Definition>> &v) {
    c.push(v.size()); // Begin's position, to be consumed by Repeat/Until
    v.push_back(make_shared<Begin>());
}

void Compiler::AddWhile(vector<shared_ptr<Definition>> &v) {
    size_t dest = c.top(); c.pop();
    c.push(v.size()); // Add While's position under the position of Begin
    c.push(dest);
    v.push_back(make_shared<If>()); // While is functionally identical to If
}

void Compiler::AddRepeat(vector<shared_ptr<Definition>> &v) {
    size_t dest = c.top(); c.pop(); // Begin's position
    size_t orig = c.top(); c.pop(); // While's position
    size_t o_res = v.size();
    v[orig]->Compile(o_res); // Resolve While, giving it jump to Repeat
    v.push_back(make_shared<Repeat>());
    v[o_res]->Compile(dest); // Resolve the now added Repeat, giving it jump to Begin
}

void Compiler::AddDo(vector<shared_ptr<Definition>> &v) {
    c.push(v.size());  // the loop-sys has the following format (from the bottom):
    c.push(-1);  //         (1) Do's position, (2) -1, (3) positions of related Leaves, (4) -1
    c.push(-1);
    v.push_back(make_shared<Do>());
}

void Compiler::AddLoop(vector<shared_ptr<Definition>> &v, bool plus) {
    size_t res = v.size();
    c.pop(); // remove the enclosing -1 of loop-sys
    ptrdiff_t i = c.top(); c.pop();
    while (i != -1) {   // compile all Leaves with jumps after this Loop
        v[i]->Compile(res);
        i = c.top(); c.pop();
    }
    c.pop();  // remove the other enclosing -1
    i = c.top(); c.pop(); // get Do's position
    if (plus)
        v.push_back(make_shared<PLoop>());
    else
        v.push_back(make_shared<Loop>());
    v[res]->Compile(i); // set up (P)Loop's jump to Do's position
}

void Compiler::AddLeave(std::vector<std::shared_ptr<Definition>> &v) {
    Stack tmp;
    for (; c.top() != -1; c.pop()) // find the nearest loop-sys
        tmp.push(c.top());

    c.pop(); // remove the enclosing -1
    c.push(v.size()); // append Leave's position to loop-sys
    c.push(-1); // add the -1 back
    for (; !tmp.empty(); tmp.pop())
        c.push(tmp.top());

    v.push_back(make_shared<Leave>());
}