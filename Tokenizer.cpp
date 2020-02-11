#include <sstream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::istream &in) : in(in) {}

std::string Tokenizer::getUntil(char c) {
    std::string res;
    for (int r = in.get(); r != EOF && r != c; r = in.get()) {
        res += static_cast<char>(r);
    }
    return res;
}

std::string Tokenizer::getToken() {
    int c = in.peek();
    //skip all whitespace except newline
    while (c != EOF && isspace(c) && c != '\n') {
        in.get();
        c = in.peek();
    }

    if (c == '\n') {
        in.get();
        return "\n";
    }

    std::string res;
    while (c != EOF && !isspace(c)) {
        res += static_cast<char>(c);
        in.get();
        c = in.peek();
    }
    return res;
}

bool Tokenizer::isNumeric(std::string token) {
    if (token.empty()) return false;
    size_t i = 0;
    if (token[0] == '-') ++i;
    for (; i < token.size(); ++i)
        if (!isdigit(token[i])) return false;
    return true;
}

int Tokenizer::getInt(const std::string &token) {
    int i = 0;
    std::stringstream ss(token);
    ss >> i;
    return i;
}
