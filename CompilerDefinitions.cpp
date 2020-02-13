#include <iostream>
#include "CompilerDefinitions.hpp"

void If::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    auto a = s.top(); s.pop();
    if (!a) ip = jmp;
}

void Else::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    ip = jmp;
}

void Then::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {}

void Begin::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {}

void Repeat::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    ip = jmp;
}

void Do::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    auto first = s.top(); s.pop();
    auto limit = s.top(); s.pop();
    r.push(limit);
    r.push(first);
}

void Loop::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    auto index = r.top(); r.pop();
    ++index;
    if (index >= r.top())
        r.pop();
    else {
        r.push(index);
        ip = jmp;
    }
}

void PLoop::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    auto index = r.top(); r.pop();
    auto plus = s.top(); s.pop();
    index += plus;
    if (index >= r.top())
        r.pop();
    else {
        r.push(index);
        ip = jmp;
    }
}

void Leave::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    r.pop(); r.pop();
    ip = jmp;
}

void PrintStr::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    std::cout << str << ' ';
}

void Recurse::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    ptrdiff_t dummy_ip;
    def.Run(s, r, dummy_ip);
}
