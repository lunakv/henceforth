#include "Definition.hpp"

void CustomDefinition::Run(Stack &s, Stack &r, ptrdiff_t &sp) const {
    for (ptrdiff_t i = 0; i < v.size(); ++i) {
        v[i]->Run(s, r, i);
    }
}
