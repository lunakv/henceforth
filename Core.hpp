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
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class DivMod : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class RShift : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class LShift : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Yes : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class No : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Const : public Definition {
    ptrdiff_t c{};
    void Run(Stack &s, Stack &r, size_t &ip) const override;
public:
    explicit Const(ptrdiff_t c);
};
class More : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Less : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Eq : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class And : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Or : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Xor : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Max : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Min : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Within : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};

// Other definitions
class Dup : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Drop : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Print : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Cr : public Definition {
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
#endif //HENCEFORTH_CORE_HPP
