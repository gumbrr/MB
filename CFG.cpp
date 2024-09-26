//
// Created by adamb on 25/09/2024.
//

#include "CFG.h"

CFG::CFG() {
    nonTerminals = {"BINDIGIT", "S"};
    terminals = {"0", "1", "a", "b"};
    productionRules = {
            {"BINDIGIT", {"0", "1"}},
            {"S", {"", "a S b BINDIGIT"}},
    };
    startSymbol = "S";
}

CFG::CFG(const string& file) {
    ifstream input(file);
    json j;
    input >> j;


}


void CFG::print() {
    cout << "V = {";
    for (auto it = nonTerminals.begin(); it != nonTerminals.end(); it++) {
        cout << *it;
        if (it != --nonTerminals.end()) {
            cout << ", ";
        }
    }
    cout << "}\n";

    cout << "T = {";
    for (auto it = terminals.begin(); it != terminals.end(); it++) {
        cout << *it;
        if (it != --terminals.end()) {
            cout << ", ";
        }
    }
    cout << "}\n";

    cout << "P = {\n";
    for (auto it = productionRules.begin(); it != productionRules.end(); it++) {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << "    " << it->first << " -> `" << *it2 << "`\n";
        }
    }
    cout << "}\n";

    cout << "S = " << startSymbol << "\n";
}


