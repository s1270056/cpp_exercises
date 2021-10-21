#include <iostream>
#include "inc.h"

double inc(double &x){
    x++;
    return x;
}

double inc(double *y){
    (*y)++;
    return *y;
}