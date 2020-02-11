#ifndef HENCEFORTH_COMPILER_HPP
#define HENCEFORTH_COMPILER_HPP

#include "Tokenizer.hpp"
#include "CompilerDefinitions.hpp"
#include "Core.hpp"

class Compiler {
    Tokenizer &t;
    CStack c;
    bool AddCompileWord(std::vector<std::shared_ptr<Definition>> &v, const std::string &token);
    void AddIf(std::vector<std::shared_ptr<Definition>> &v);
    void AddElse(std::vector<std::shared_ptr<Definition>> &v);
    void AddThen(std::vector<std::shared_ptr<Definition>> &v);
    void AddBegin(std::vector<std::shared_ptr<Definition>> &v);
    void AddRepeat(std::vector<std::shared_ptr<Definition>> &v);
    void AddWhile(std::vector<std::shared_ptr<Definition>> &v);
    void AddDo(std::vector<std::shared_ptr<Definition>> &v);
    void AddLoop(std::vector<std::shared_ptr<Definition>> &v, bool plus);
    void AddLeave(std::vector<std::shared_ptr<Definition>> &v);
public:
    explicit Compiler(Tokenizer &t);
    void AddDefinition(DDRef d);
};

#endif //HENCEFORTH_COMPILER_HPP
