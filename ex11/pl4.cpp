#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

namespace PL4 {  
 template <class FwdIt>
 void sort(FwdIt begin, FwdIt end){

            for (FwdIt i = begin; i != end; ++i){
        for (FwdIt j = begin; j < i; ++j){
            if (*i < *j)
                std::iter_swap(i, j);
             }
         }

     }
 };


int main(){
    vector<int> vt;
    vt.push_back(6);
    vt.push_back(4);
    vt.push_back(7);
    vt.push_back(2);
    vt.push_back(8);
    vt.push_back(2);

        vector<double> vt2;
    vt2.push_back(7.0);
    vt2.push_back(6.3);
    vt2.push_back(2.9);
    vt2.push_back(-3);
    vt2.push_back(9);
    vt2.push_back(6.5);


        vector<char> vt3;
    vt3.push_back('a');
    vt3.push_back('z');
    vt3.push_back('e');
    vt3.push_back('b');
    vt3.push_back('n');
    vt3.push_back('l');

    vector<int>::iterator it = vt.begin();
    while(it != vt.end()){
        cout << *it<< ", ";
        it++;
}
    cout << "\n";

        vector<double>::iterator it2 = vt2.begin();
    while(it2 != vt2.end()){
        cout << *it2<< ", ";
        it2++;
}
    cout << "\n";

        vector<char>::iterator it3 = vt3.begin();
    while(it3 != vt3.end()){
        cout << *it3<< ", ";
        it3++;
}
    cout << "\n";


    PL4::sort(vt.begin(), vt.end());
    it = vt.begin();
    while(it != vt.end()){
        cout << *it<< ", ";
        it++;
    }
    cout << "\n";


    cout <<  fixed << setprecision(1);


    PL4::sort(vt2.begin(), vt2.end());
    it2 = vt2.begin();
    while(it2 != vt2.end()){
        cout << *it2 << ", ";
        it2++;
    }
    cout << "\n";


    PL4::sort(vt3.begin(), vt3.end());
    it3 = vt3.begin();
    while(it3 != vt3.end()){
        cout << *it3<< ", ";
        it3++;
    }
    cout << "\n";

    
}