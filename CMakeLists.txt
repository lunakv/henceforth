cmake_minimum_required(VERSION 3.15)
project(henceforth)

set(CMAKE_CXX_STANDARD 20)

add_executable(henceforth main.cpp Tokenizer.cpp Tokenizer.hpp StackObject.hpp StackObject.cpp Definition.cpp Definition.hpp CoreDefinitions.hpp)