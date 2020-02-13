#ifndef HENCEFORTH_EXCEPTIONS_HPP
#define HENCEFORTH_EXCEPTIONS_HPP

#include <exception>
#include <string>

class HenceforthException : public std::exception {};

class UnknownWord : public HenceforthException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Unknown word encountered";
    }
};

class StackUnderflow : public HenceforthException {
    [[nodiscard]] const char* what() const noexcept override {
        return "Stack underflow";
    }
};

#endif //HENCEFORTH_EXCEPTIONS_HPP
