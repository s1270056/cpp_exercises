// test_inc.cpp
#include <cassert>
// COMPLETE Include any additional necessary headers here
#include <iostream>
#include "inc.h"

int main(void)
{
    double a = 1.0;
    inc(a);
    assert(a == 2.0);
    inc(a);
    assert(a == 3.0);

    a = 1.0;
    inc2(&a);
    assert(a == 2.0);
    inc2(&a);
    assert(a == 3.0);
    return 0;
}