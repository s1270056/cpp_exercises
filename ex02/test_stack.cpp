#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main(void)
{
    Stack stack1;
    std::string moji;

    if (stack1.empty())
        cout << "stack is empty" << endl;
    else
        cout << "stack is not empty" << endl;

    stack1.push("Hello");
    stack1.push("World");
    stack1.push("Good");
    stack1.push("Morning");
    stack1.push("s1270056");
    stack1.push("Tanaka");
    stack1.push("Takaaki");

    if (stack1.full())
        cout << "stack is full" << endl;
    else
        cout << "stack is not full" << endl;

    cout << "top: " << stack1.top() << " size: " << stack1.size() << endl;
    stack1.pop();
    cout << "pop: 1 "<< "top: " << stack1.top() << " size: " << stack1.size() << endl;
    stack1.pop();
    stack1.pop();
    cout << "pop: 2 "<< "top: " << stack1.top() << " size: " << stack1.size() << endl;
    stack1.pop();
    cout << "pop: 1 "<< "top: " << stack1.top() << " size: " << stack1.size() << endl;
}