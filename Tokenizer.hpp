//
// Created by vaasa on 2/2/20.
//

#ifndef HENCEFORTH_TOKENIZER_HPP
#define HENCEFORTH_TOKENIZER_HPP

#include <istream>
#include <vector>
#include "StackObject.hpp"

using TokenList = std::vector<std::string>;

class Tokenizer {
public:
    std::string getToken(std::istream &in);
    std::string getUntil(std::istream &in, char c);
    TokenList getTokensUntil(std::istream &in, std::string s);
    bool isNumeric(std::string token);
    int getInt(std::string token);
};

#endif //HENCEFORTH_TOKENIZER_HPP
