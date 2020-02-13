#include "Interpreter.hpp"
#include "Exceptions.hpp"
using namespace std;

void Interpreter::Run() {
    for (string token = t.GetToken(); !token.empty(); token = t.GetToken()) {
        try {
            if (token == "\\")
                t.SkipLine();
            else if (token == ":")
                c.AddDefinition(dict);
            else
                ExecuteCommand(token);
        }
        catch (const HenceforthException &e) {
            cout << "Error: " << e.what() << endl
                 << "Encountered while parsing token" << endl
                 << ">>>" << token << "<<<" << endl;
        }
    }
}

void Interpreter::ExecuteCommand(const string &token) {
    if (dict->count(token)) {
        ptrdiff_t dummy_ip;
        (*dict)[token]->Run(s, r, dummy_ip);
    }
    else if (Tokenizer::IsNumeric(token)) {
        s.push(Tokenizer::GetNum(token));
    }
    else {
        throw UnknownWord();
    }
}
