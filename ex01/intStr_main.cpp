#include <iostream>
#include <cstdlib>
#include "intStr.h"

int main(){
    int a = -12345;
    char *b;
    const char *c = "-12345";
    int d;

    b = intToStr(a);
    printf("%s \n",b);
    
    d = strToInt(c);
    printf("%d ",d);
    return 0;
}