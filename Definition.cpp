#include "Definition.hpp"
#include "Exceptions.hpp"

ptrdiff_t & Stack::top() {
    if (s.empty()) throw StackUnderflow();
    return s.top();
}

void Stack::pop() {
    if (s.empty()) throw StackUnderflow();
    s.pop();
}

void CustomDefinition::Run(Stack &s, Stack &r, size_t &ip) const {
    for (size_t i = 0; i < v.size(); ++i) {
        v[i]->Run(s, r, i);
    }
}
