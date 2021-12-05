#include <iostream>
#include "inc.h"

void inc(double &x){
    x++;
}

void inc2(double *y){
    (*y)++;
}