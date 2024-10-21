#include <iostream>
#include "CFG.h"
#include "PDA.h"

using namespace std;

int main() {
    PDA pda("testfiles//input-pda2cfg1.json");
    //pda.toCFG().print();
    return 0;
}