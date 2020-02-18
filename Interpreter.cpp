#include "Interpreter.hpp"
#include "Exceptions.hpp"

using namespace std;

void Interpreter::Run(istream &in, bool quiet) {
    if (!quiet)
        cout << "Type 'bye' to exit." << endl;
    Tokenizer t(in);
    Compiler c(t);
    for (string token = t.GetToken(); !token.empty(); token = t.GetToken()) { // read all of input
        try {
            for (; token != "\n" && !token.empty(); token = t.GetToken()) {   // try block by line
                if (token == ":")                                             // enter compile mode
                    c.AddDefinition(dict);
                else if (token == "BYE")
                    return;
                else
                    ExecuteCommand(token);
            }

            if (!quiet)
                cout << " ok" << endl; // print confirmation iff whole line was successful
        }
        catch (const HenceforthException &e) {
            cout << endl           // display information about caught exception
                 << "Error: " << e.what() << endl
                 << "encountered while parsing token:" << endl
                 << ">>>" << token << "<<<" << endl;
            t.SkipLine();          // stop parsing the current line
        }
    }
}

void Interpreter::ExecuteCommand(const string &token) {
    if (dict.count(token)) {
        size_t dummy_ip(0);
        dict[token]->Run(s, r, dummy_ip);
    }
    else if (Tokenizer::IsNumeric(token)) {
        s.push(Tokenizer::GetNum(token));
    }
    else {
        throw UnknownWord();
    }
}
