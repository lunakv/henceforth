#include "CompilerDefinitions.hpp"

void If::Run(SStack &s, RStack &r, int &sp) {
    auto a = s.top(); s.pop();
    if (!a.val) sp = jmp;
}

void Else::Run(SStack &s, RStack &r, int &sp) {
    sp = jmp;
}

void Then::Run(SStack &s, RStack &r, int &sp) {}

void Begin::Run(SStack &s, RStack &r, int &sp) {}

void Repeat::Run(SStack &s, RStack &r, int &sp) {
    sp = jmp;
}

void Until::Run(SStack &s, RStack &r, int &sp) {
    auto x = s.top(); s.pop();
    if (!x.val)
        sp = jmp;
}

void Do::Run(SStack &s, RStack &r, int &sp) {
    auto first = s.top(); s.pop();
    auto limit = s.top(); s.pop();
    r.emplace(limit);
    r.emplace(first);
}

void Loop::Run(SStack &s, RStack &r, int &sp) {
    auto index = r.top(); r.pop();
    ++index.val;
    if (index.val >= r.top().val)
        r.pop();
    else {
        r.push(index);
        sp = jmp;
    }
}

void PLoop::Run(SStack &s, RStack &r, int &sp) {
    auto index = r.top(); r.pop();
    auto plus = s.top(); s.pop();
    index.val += plus.val;
    if (index.val >= r.top().val)
        r.pop();
    else {
        r.push(index);
        sp = jmp;
    }
}

void Leave::Run(SStack &s, RStack &r, int &sp) {
    r.pop(); r.pop();
    sp = jmp;
}
