#include "Calculator.h"
#define ll long long



long long Calculator::calculate(std::string str) {
    Stack S;
    int Findex = 0;
    int Eindex = 0;

    for (int i = 0 ; i < str.length(); ++i) {

        if (str[i] == ' ') continue;


        if ( (str[i] != '+') && (str[i] != '-') && (str[i] != '*')) {
            std::string stmp;

            while(str[i] != ' ') {
                stmp += str[i];
                ++i;
            }
            const char* atmp = stmp.c_str();

            S.Push(1LL * atoi(atmp));
        }

        else {

            ll b = S.Pop();
            ll a = S.Pop();



            switch (str[i]) {
                case '+':
                    S.Push(a+b);
                    break ;
                case '-':
                    S.Push(a-b);
                    break ;
                case '*':
                    S.Push(a*b);
                    break ;
            }

        }
    }

    return 1LL * S.Pop();
}