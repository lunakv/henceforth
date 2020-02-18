#ifndef HENCEFORTH_CORE_HPP
#define HENCEFORTH_CORE_HPP

#include <map>
#include <memory>
#include "Definition.hpp"

// includes all interpretable word definitions and provides a dictionary linking them to tokens
DefDict GetCoreDict();

// Definitions for basic arithmetic functions.
class Add : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Sub : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Mul : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Div : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Mod : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class DivMod : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class RShift : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class LShift : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Yes : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class No : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Const : public Definition {
    ptrdiff_t c{};
public:
    explicit Const(ptrdiff_t c);
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class More : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Less : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Eq : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class NotEq : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class And : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Or : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Xor : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Max : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Min : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Within : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class AddOne : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class SubOne : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Double : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Half : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class IsZero : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class IsNeg : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Negate : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Invert : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};

// Other definitions
class Dup : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Drop : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Print : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Cr : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Swap : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Over : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Rot : public Definition {
public:
    void Run(Stack &s, Stack &r ,size_t &ip) const override;
};
class Depth : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
#endif //HENCEFORTH_CORE_HPP
