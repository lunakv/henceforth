#include "Definition.hpp"

#include <utility>

CustomDefinition::CustomDefinition(std::vector<std::shared_ptr<Definition>> v) : v(std::move(v))
{}

void CustomDefinition::Run(SStack &s, RStack &r, int &sp) {
    for (int i = 0; i < v.size(); ++i) {
        v[i]->Run(s, r, i);
    }
}

void Branching::Compile(size_t res) {
    jmp = res;
}
