#ifndef HENCEFORTH_COMPILERDEFINITIONS_HPP
#define HENCEFORTH_COMPILERDEFINITIONS_HPP

#include "Definition.hpp"
// List of definitions with semantics defined only when used in the compilation environment

class If : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Else : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Then : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Begin : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Repeat : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Do : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class CheckedDo : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Loop : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class PLoop : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Leave : public Branching {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Unloop : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class I : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class J : public Definition {
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class PrintStr : public Definition {
    const std::string str;
public:
    explicit PrintStr(std::string str) : str(std::move(str)) {}
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Recurse : public Definition {
    const Definition &def;  // a reference is used, since shared_ptr would cause a cyclic dependency
public:
    explicit Recurse(const Definition &def) : def(def) {}
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
class Exit : public Definition {
    const CustomDefinition &def;
public:
    explicit Exit(const CustomDefinition &def) : def(def) {}
    void Run(Stack &s, Stack &r, size_t &ip) const override;
};
#endif //HENCEFORTH_COMPILERDEFINITIONS_HPP