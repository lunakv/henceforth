#ifndef HENCEFORTH_TOKENIZER_HPP
#define HENCEFORTH_TOKENIZER_HPP

#include <istream>
#include <vector>

// Class for producing word tokens from input
class Tokenizer {
    std::istream &in;
public:
    explicit Tokenizer(std::istream &in) : in(in) {};
    std::string GetToken();
    std::string GetUntil(char c);
    static bool IsNumeric(std::string token);
    static ptrdiff_t GetNum(const std::string &token);
};

#endif //HENCEFORTH_TOKENIZER_HPP
