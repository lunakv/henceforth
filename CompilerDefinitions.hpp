#ifndef HENCEFORTH_COMPILERDEFINITIONS_HPP
#define HENCEFORTH_COMPILERDEFINITIONS_HPP

#include "Definition.hpp"
// List of definitions with semantics defined only when used in the compilation environment

class If : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Else : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Then : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Begin : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Repeat : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Do : public Definition {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Loop : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class PLoop : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Leave : public Branching {
public:
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class PrintStr : public Definition {
    const std::string str;
public:
    explicit PrintStr(std::string str) : str(std::move(str)) {}
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
class Recurse : public Definition {
    const Definition& def;
public:
    explicit Recurse(const Definition& def) : def(def) {}
    void Run(Stack &s, Stack &r, ptrdiff_t &ip) const override;
};
#endif //HENCEFORTH_COMPILERDEFINITIONS_HPP