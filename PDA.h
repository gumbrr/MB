//
// Created by adamb on 21/10/2024.
//

#ifndef CFG_PDA_H
#define CFG_PDA_H

#include <iostream>
#include <vector>
#include "json.hpp"
#include <fstream>
#include <sstream>


using namespace std;
using json = nlohmann::json;

struct transition {
    string from;
    string input;
    string stacktop;
    string to;
    vector<string> replacement;
};

class PDA {
private:
    vector<string> states;
    vector<string> alphabet;
    vector<string> stackAlphabet;
    vector<transition> transitions;
    string startState;
    string startStack;

public:
    PDA() = default;
    explicit PDA(const string& file);
    vector<string> getVariables();


};


#endif //CFG_PDA_H
