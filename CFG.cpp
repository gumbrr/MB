//
// Created by adamb on 25/09/2024.
//

#include "CFG.h"

CFG::CFG(const string& file) {
    ifstream input(file);
    json j;
    input >> j;

    for(const auto& elem : j["Variables"]) {
        nonTerminals.push_back(elem.get<std::string>());
    }
    sort(nonTerminals.begin(), nonTerminals.end());

    for(const auto& elem : j["Terminals"]) {
        terminals.push_back(elem.get<string>());
    }
    sort(terminals.begin(), terminals.end());

    for(const auto& elem : j["Productions"]) {
        auto head = elem["head"].get<string>();
        string body;

        for(size_t i = 0; i < elem["body"].size(); ++i) {
            body += elem["body"][i].get<string>();
            if (i != elem["body"].size() - 1) {
                body += " ";
            }
        }
        productionRules[head].push_back(body);
        sort(productionRules[head].begin(), productionRules[head].end());
    }
    startSymbol = j["Start"];
}

void CFG::print() const {
    cout << "V = {";
    for (int i = 0; i < nonTerminals.size(); i++) {
        cout << nonTerminals[i];
        if (i != nonTerminals.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    cout << "T = {";
    for (int i = 0; i < terminals.size(); i++) {
        cout << terminals[i];
        if (i != terminals.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    cout << "P = {\n";
    for (const auto & productionRule : productionRules) {
        for (const string& rule: productionRule.second) {
            cout << "    " << productionRule.first << " -> `" << rule << "`\n";
        }
    }
    cout << "}\n";

    cout << "S = " << startSymbol << "\n";
}