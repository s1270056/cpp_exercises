#include <vector>
#include <iostream>
#include <algorithm>
#include "median.h"

using namespace std;

int main(void){

    int k=2;

    vector<double> num;
    num.push_back(7.0);
    num.push_back(14.0);
    num.push_back(10.0);
    num.push_back(12.0);
    num.push_back(2.0);
    num.push_back(11.0);
    num.push_back(29.0);
    num.push_back(3.0);
    num.push_back(4.0);

    double median = compute_median(num);

    cout << "Median: " << median << endl;
    cout << "k: " << k << endl;
    
    vector<double> close = compute_k_closest(k, num);

    cout << "The k-closest: " << endl;

    for (int i = 0; i < k; ++i) {
        cout << close[i] << ", ";
    }

    cout << endl;



}