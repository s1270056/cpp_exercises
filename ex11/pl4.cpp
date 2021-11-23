#include <iostream>
#include <vector>

using namespace std;

namespace PL4 {  
 template <class FwdIt>
 void sort(FwdIt begin, FwdIt end){
     int tmp;
     int tmp2;
     int flag=0;


     for(FwdIt i=end; i>begin; i--){
         for(FwdIt j=begin; j<(i-1); j++){
             flag++;    
             tmp = *begin;  
             //cout << tmp;
             (begin++);     
             //cout << *begin << endl;

             if(tmp > *begin){  
                 tmp2 = *begin; 
                 *begin = tmp;  
                 (begin--); 
                 *begin = tmp2; 
                 (begin++); 
             }
         }
            
             (begin -= flag);
             flag = 0;

     }
 };
}

int main(){
    vector<int> vt;
    vt.push_back(6);
    vt.push_back(4);
    vt.push_back(7);
    vt.push_back(2);
    vt.push_back(8);
    vt.push_back(2);

    vector<int>::iterator it = vt.begin();
    while(it != vt.end()){
        cout << *it;
        it++;
    }
    cout << "\n";


    PL4::sort(vt.begin(), vt.end());
    it = vt.begin();
    while(it != vt.end()){
        cout << *it;
        it++;
    }
    cout << "\n";

    
}