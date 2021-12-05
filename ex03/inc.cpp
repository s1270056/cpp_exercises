#include <iostream>
#include "inc.h"

void inc(double &x){
    x++;
}

void inc(double *y){
    (*y)++;
}