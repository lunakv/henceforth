#ifndef HENCEFORTH_TOKENIZER_HPP
#define HENCEFORTH_TOKENIZER_HPP

#include <istream>
#include <vector>
#include "StackObject.hpp"

using TokenList = std::vector<std::string>;

class Tokenizer {
    std::istream &in;
public:
    explicit Tokenizer(std::istream &in);
    std::string getToken();
    std::string getUntil(char c);
    bool isNumeric(std::string token);
    int getInt(const std::string &token);
};

#endif //HENCEFORTH_TOKENIZER_HPP
