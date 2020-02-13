#ifndef HENCEFORTH_COREDEFINITIONS_HPP
#define HENCEFORTH_COREDEFINITIONS_HPP

// Non-arithmetic definitions belonging to the Core dictionary
#include "Definition.hpp"

class Dup : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Drop : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Print : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Cr : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
#endif //HENCEFORTH_COREDEFINITIONS_HPP
