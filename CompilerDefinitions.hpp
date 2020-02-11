#ifndef HENCEFORTH_COMPILERDEFINITIONS_HPP
#define HENCEFORTH_COMPILERDEFINITIONS_HPP

#include "Definition.hpp"

class If : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Else : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Then : public Definition {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Begin : public Definition {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Repeat : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class While : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Until : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Do : public Definition {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Loop : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class PLoop : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
class Leave : public Branching {
public:
    void Run(SStack &s, RStack &r, int &sp) override;
};
#endif //HENCEFORTH_COMPILERDEFINITIONS_HPP