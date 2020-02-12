#ifndef HENCEFORTH_ARITHMETICDEFINITIONS_HPP
#define HENCEFORTH_ARITHMETICDEFINITIONS_HPP

#include "Definition.hpp"
// Definitions for basic arithmetic functions.

class Add : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Sub : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Mul : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Div : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Mod : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class DivMod : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class RShift : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class LShift : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Yes : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class No : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Const : public Definition {
    ptrdiff_t c{};
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
public:
    explicit Const(ptrdiff_t c);
};
class More : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Less : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Eq : public Definition {
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};

#endif //HENCEFORTH_ARITHMETICDEFINITIONS_HPP
