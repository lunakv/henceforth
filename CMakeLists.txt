cmake_minimum_required(VERSION 3.13)
project(henceforth)

set(CMAKE_CXX_STANDARD 20)

add_executable(henceforth main.cpp Tokenizer.cpp Tokenizer.hpp Definition.hpp ArithmeticDefinitions.hpp ArithmeticDefinitions.cpp Core.cpp Core.hpp CompilerDefinitions.cpp CompilerDefinitions.hpp Compiler.cpp Compiler.hpp Definition.cpp)
