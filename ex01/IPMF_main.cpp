#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "IPMF.h"
using namespace std;

int main()
{
    double a, b, c, d, e;
    a = binomialPMF(5, 0.25, 1);
    b = binomialPMF(5, 0.25, 2);
    c = binomialPMF(25, 0.25, 2);
    d = binomialPMF(25, 0.25, 10);
    e = binomialPMF(25, 0.25, 15);

    cout << fixed << setprecision(6) << a << endl;
    cout << fixed << setprecision(6) << b << endl;
    cout << fixed << setprecision(7) << c << endl;
    cout << fixed << setprecision(7) << d << endl;
    cout << fixed << setprecision(9) << e << endl;
}