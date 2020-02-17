#include <sstream>
#include <limits>
#include "Tokenizer.hpp"

// returns a string containing all chars from current position to next occurrence of c (non-inclusive)
std::string Tokenizer::GetUntil(char c) {
    in.get();   // skip the space separating the previous token from wanted text
    std::string res;
    for (int r = in.get(); r != EOF && r != c; r = in.get()) {
        res += static_cast<char>(r);
    }
    return res;
}

// returns the next whitespace-separated word from input
std::string Tokenizer::GetToken() {
    int c = in.peek();
    while (isspace(c) && !in.eof() && c != '\n') {
        in.get();
        c = in.peek();
    }

    if (c == '\n') {
        in.get();
        return "\n";
    }

    std::string res;
    in >> res;  // in is either on non-whitespace or on EOF
    if (res == "\\") {  // ignore comments
        SkipLine();
        return "\n";
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

void Tokenizer::SkipLine() {
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
