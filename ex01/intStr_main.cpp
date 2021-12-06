#include <iostream>
#include <cstdlib>
#include "intStr.h"
using namespace std;

int main(){
    int a = -12345;
    char *b = intToStr(a);;
    const char *c = "-12345";
    int d = strToInt(c);

    cout << b << endl;
    cout << d << endl;
    return 0;
}