//
// Created by adamb on 25/09/2024.
//

#ifndef CFG_CFG_H
#define CFG_CFG_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

class CFG {
private:
    vector<string> terminals;
    vector<string> nonTerminals;
    map<string, vector<string>> productionRules;
    string startSymbol;
public:
    CFG();
    CFG(const string& file);
    void print();
};


#endif //CFG_CFG_H
