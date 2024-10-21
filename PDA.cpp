//
// Created by adamb on 21/10/2024.
//

#include "PDA.h"


PDA::PDA(const string& file){
    ifstream input(file);
    json j;
    input >> j;

    for(const auto& elem : j["States"]) {
        states.push_back(elem.get<string>());
    }

    for(const auto& elem : j["Alphabet"]) {
        alphabet.push_back(elem.get<string>());
    }

    for(const auto& elem : j["StackAlphabet"]) {
        stackAlphabet.push_back(elem.get<string>());
    }

    for(const auto& elem : j["Transitions"]) {
        transition tran;
        tran.from = elem["from"].get<string>();
        tran.input = elem["input"].get<string>();
        tran.stacktop = elem["stacktop"].get<string>();
        tran.to = elem["to"].get<string>();
        tran.replacement = elem["replacement"].get<std::vector<string>>();
        transitions.push_back(tran);
    }

    startState = j["StartState"].get<string>();

    startStack = j["StartStack"].get<string>();
}


vector<string> PDA::getVariables(){
    vector<string> nonTerminals;

    for(const string& s1 : states){
        for(const string& s2 : stackAlphabet){
            for(const string& s3 : states){
                std::ostringstream oss;
                oss << "[" << s1 << "," << s2 << "," << s3 << "]";
                std::string variable = oss.str();
                nonTerminals.push_back(variable);
            }
        }
    }
    return nonTerminals;
}
