#include "CoreDefinitions.hpp"
#include <iostream>

void Dup::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.push(s.top());
}

void Drop::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.pop();
}

void Print::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    std::cout << s.top() << ' ';
    s.pop();
}

void Cr::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    std::cout << std::endl;
}
