#include "Interpreter.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    Interpreter inter;
    // load all files from arguments
    for (size_t i = 1; i < argc; ++i) {
        fstream fs(argv[i]);
        if (!fs) {
            cerr << "Error: couldn't open file: '" << argv[i] << "'. Exiting..." << endl;
            return 1;
        }

        inter.Run(fs, true);
    }

    // start interactive mode
    inter.Run(cin, false);
    return 0;
}
