#include <iostream>
#include <cstring>
#include <stack>
#include <sstream>
#include <vector>
#include <iomanip>


using namespace std;

double twostack(const string str){
    double x, y;
    char flag;
    stringstream sstr(str);
    stack<double> num;
    stack<char> ope;
    string st;

    while(sstr >> st){

        if(st == "+" || st == "-" || st == "*" || st == "/"){
            flag = *st.c_str();
            ope.push(flag);

            continue;
        }
        else if(st == "("){
            continue;
           
        }
        else if(st == ")"){
            if(ope.top() == '+'){
                ope.pop();
               
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x + y);
            }
            else if(ope.top() == '-'){
                ope.pop();
                
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x - y);
            }
            else if(ope.top() == '*'){
                ope.pop();
               
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x * y);
            }
            else if(ope.top() == '/'){
                ope.pop();
                
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x / y);
            }
            continue;

        }
        else{
            num.push(stod(st));
            continue;
        }
    }
    return num.top();
}

int main(){
    string str1 = "( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )";
    string str2 = "( ( ( 2.0 * ( 3.0 - 1.0 ) ) - 5.0 ) * 3.0 )";
    
    cout <<  fixed << setprecision(1);

    cout << "Input: " << str1 << endl;
    cout << "Output: "<< twostack(str1) << endl;

    cout << "Input: " << str2 << endl;
    cout << "Output: "<< twostack(str2) << endl;
    return 0;

}