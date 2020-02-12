#include <sstream>
#include "Tokenizer.hpp"

// returns a string containing all chars from current position to next occurrence of c (non-inclusive)
std::string Tokenizer::GetUntil(char c) {
    std::string res;
    for (ptrdiff_t r = in.get(); r != EOF && r != c; r = in.get()) {
        res += static_cast<char>(r);
    }
    return res;
}

// returns the next whitespace-separated word from input, or "\n" if end-of-line was reached
std::string Tokenizer::GetToken() {
    ptrdiff_t c = in.peek();
    //skip all whitespace except newline
    while (c != EOF && isspace(c) && c != '\n') {
        in.get();
        c = in.peek();
    }

    // newlines are a special token for ptrdiff_terpreter
    if (c == '\n') {
        in.get();
        return "\n";
    }

    std::string res;
    // get all chars until a whitespace
    while (c != EOF && !isspace(c)) {
        res += static_cast<char>(c);
        in.get();
        c = in.peek();
    }
    return res; // returns empty string once input ends
}

bool Tokenizer::IsNumeric(std::string token) {
    if (token.empty()) return false;
    size_t i = 0;
    if (token[0] == '-') ++i;
    for (; i < token.size(); ++i)
        if (!isdigit(token[i])) return false;
    return true;
}

ptrdiff_t Tokenizer::GetNum(const std::string &token) {
    ptrdiff_t i = 0;
    std::stringstream ss(token);
    ss >> i;
    return i;
}
