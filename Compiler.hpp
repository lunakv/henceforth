#ifndef HENCEFORTH_COMPILER_HPP
#define HENCEFORTH_COMPILER_HPP

#include "Tokenizer.hpp"
#include "CompilerDefinitions.hpp"
#include "Core.hpp"

class Compiler {
    Tokenizer &t;
    Stack c;
    bool AddCompileWord(CustomDefinition &d, const std::string &token);
    void AddIf(CustomDefinition &d);
    void AddElse(CustomDefinition &d);
    void AddThen(CustomDefinition &d);
    void AddBegin(CustomDefinition &d);
    void AddRepeat(CustomDefinition &d);
    void AddAgain(CustomDefinition &d);
    void AddWhile(CustomDefinition &d);
    void AddDo(CustomDefinition &d);
    void AddLoop(CustomDefinition &d, bool plus);
    void AddIndex(CustomDefinition &d, bool i);
    void AddLeave(CustomDefinition &d);
    void AddUnloop(CustomDefinition &d);
    void AddPrintStr(CustomDefinition &d);
    void AddRecurse(CustomDefinition &d);
    void AddExit(CustomDefinition &d);
public:
    explicit Compiler(Tokenizer &t) : t(t) {};
    void AddDefinition(DefDict &dict);
};

#endif //HENCEFORTH_COMPILER_HPP
