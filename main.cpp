#include "Interpreter.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    bool exit = false;
    Interpreter inter;
    // load all files from arguments
    for (size_t i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-e")) {   // don't enter interactive mode
            exit = true;
            continue;
        }

        fstream fs(argv[i]);
        if (!fs) {
            cerr << "Error: couldn't open file: '" << argv[i] << "'. Exiting..." << endl;
            return 1;
        }

        inter.Run(fs, true);
    }

    // start interactive mode
    if (!exit)
        inter.Run(cin, false);
    return 0;
}
