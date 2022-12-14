#include <iostream>|
#include <cassert>

#include "lib/Calculator.h"

void Test_Calc() {

    std::string TestN;
    Calculator* Calc;

    Calc = new Calculator;
    assert(Calc->calculate("3 2 +") == 5 );
    delete Calc;

    Calc= new Calculator;
    assert(Calc->calculate("1 0 + 1 -") == 0);
    delete Calc;

    Calc= new Calculator;
    assert(Calc->calculate("8 9 + 1 7 - * ") == -102);
    delete Calc;

    printf("All tests Passed: OK");
}

int main() {
    Test_Calc();
    return 0;
}