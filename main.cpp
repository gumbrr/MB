#include <iostream>
#include "CFG.h"

using namespace std;

int main() {
    CFG cfg("testfile.json");
    cfg.print();
    return 0;
}