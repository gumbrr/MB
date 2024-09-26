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

    for(const auto& elem : j["Variables"]) {
        nonTerminals.push_back(elem.get<std::string>());
    }
    sort(nonTerminals.begin(), nonTerminals.end());

    for(const auto& elem : j["Terminals"]) {
        terminals.push_back(elem.get<std::string>());
    }
    sort(terminals.begin(), terminals.end());

    for(const auto& elem : j["Productions"]) {
        string head = elem["head"];
        string body;

        for(const auto& elem2 : elem["body"]) {
            body += elem2.get<std::string>();
            if (elem2 != elem["body"].back()) {
                body += " ";
            }
        }
        productionRules[head].push_back(body);
        sort(productionRules[head].begin(), productionRules[head].end());
    }
    startSymbol = j["Start"];
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