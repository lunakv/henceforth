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


void Compiler::AddDefinition(DDRef d) {
    vector<shared_ptr<Definition>> v;
    string name = t.getToken();
    string token = t.getToken();
    for (; !token.empty() && token != ";"; token = t.getToken()) {
        if (token == "\n") continue;

        if (d->count(token))
            v.push_back(d->at(token));
        else if (t.isNumeric(token)) {
            auto con = make_shared<Const>(t.getInt(token));
            v.push_back(con);
        }
        else if (isCompileWord(token)) {
            AddCompileWord(v, token);
        }
        else {
            throw exception(); // Unknown token
        }
    }

    if (token.empty())
        throw exception(); // end of stream reached before end of definition

    (*d)[name] = make_shared<CustomDefinition>(std::move(v));
}

void Compiler::AddIf(vector<shared_ptr<Definition>> &v) {
    c.push(v.size());
    v.push_back(make_shared<If>());
}

void Compiler::AddElse(vector<shared_ptr<Definition>> &v) {
    size_t i = c.top(); c.pop();
    size_t res = v.size();
    v.push_back(make_shared<Else>());
    v[i]->Compile(res);
    c.push(res);
}

void Compiler::AddThen(vector<shared_ptr<Definition>> &v) {
    size_t i = c.top(); c.pop();
    v[i]->Compile(v.size());
    v.push_back(make_shared<Then>());
}

void Compiler::AddBegin(vector<shared_ptr<Definition>> &v) {
    c.push(v.size());
    v.push_back(make_shared<Begin>());
}

void Compiler::AddWhile(vector<shared_ptr<Definition>> &v) {
    size_t dest = c.top(); c.pop();
    c.push(v.size());
    c.push(dest);
    v.push_back(make_shared<If>());
}

void Compiler::AddRepeat(vector<shared_ptr<Definition>> &v) {
    size_t dest = c.top(); c.pop();
    size_t orig = c.top(); c.pop();
    size_t o_res = v.size();
    v[orig]->Compile(o_res);
    v.push_back(make_shared<Repeat>());
    v[o_res]->Compile(dest);
}

void Compiler::AddDo(vector<shared_ptr<Definition>> &v) {
    c.push(v.size());
    c.push(-1);
    v.push_back(make_shared<Do>());
}

void Compiler::AddLoop(vector<shared_ptr<Definition>> &v, bool plus) {
    size_t res = v.size();
    int i = c.top(); c.pop();
    while (i != -1) {
        v[i]->Compile(res);
        i = c.top(); c.pop();
    }
    i = c.top(); c.pop();
    if (plus)
        v.push_back(make_shared<PLoop>());
    else
        v.push_back(make_shared<Loop>());
    v[res]->Compile(i);
}

void Compiler::AddLeave(std::vector<std::shared_ptr<Definition>> &v) {
    c.push(v.size());
    v.push_back(make_shared<Leave>());
}