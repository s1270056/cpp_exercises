#ifndef Median_H
#define Median_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double compute_median(vector<double> num){
    size_t x = num.size()/2;
    int size = num.size();
    double res;
    if(size % 2 == 0){
        nth_element(num.begin(), num.begin() + x, num.end());
        size_t y = x+1;
        res = (num[x]+num[y]) / 2;
    };

    if(size % 2 == 1){
        nth_element(num.begin(), num.begin() + x, num.end());
        res = num[x];

    };
    return res;

}



vector<double> compute_k_closest(int k, const vector<double>& number){

    auto mid = compute_median(number);
    auto res = number;

    auto compare = [mid](int l, int r) {

        auto lef=abs(l - mid);
        auto rig=abs(r - mid);

        return lef < rig;

    };

    std::nth_element(res.begin(), res.begin() + res.size() / 2, res.end(), compare);
    return res;

}


#endif