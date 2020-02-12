#ifndef HENCEFORTH_COMPILERDEFINITIONS_HPP
#define HENCEFORTH_COMPILERDEFINITIONS_HPP

#include "Definition.hpp"
// List of definitions with semantics defined only when used in the compilation environment

class If : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Else : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Then : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Begin : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Repeat : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class While : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Do : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Loop : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class PLoop : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
class Leave : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) override;
};
#endif //HENCEFORTH_COMPILERDEFINITIONS_HPP