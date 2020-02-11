#ifndef HENCEFORTH_ARITHMETICDEFINITIONS_HPP
#define HENCEFORTH_ARITHMETICDEFINITIONS_HPP

#include "Definition.hpp"

class Add : public Definition {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Sub : public Definition {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Mul : public Definition {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Div : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Mod : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class RShift : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class LShift : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Yes : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class No : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Const : public Definition {
    int c{};
    void Run(SStack &s, RStack &r, int &sp) override;
public:
    explicit Const(int c);
};
class More : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Less : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Eq : public Definition {
    void Run(SStack &s, RStack &r, int &sp) override;
};

#endif //HENCEFORTH_ARITHMETICDEFINITIONS_HPP
