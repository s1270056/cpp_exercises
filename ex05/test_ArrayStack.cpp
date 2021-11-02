// test_ArrayStack.cpp
#include "ArrayStack.h"
using namespace std;

int main(void)
{
    // Create an instance of ArrayStack named stack1
    //   using the default constructor
    // Push 1.0, 2.0, 3.0, 4.0, 5.0 in this stack
    ArrayStack stack1 = ArrayStack();
    stack1.push(1.0);
    stack1.push(2.0);
    stack1.push(3.0);
    stack1.push(4.0);
    stack1.push(5.0);

    // stack1.pop();
    // cout << stack1.top() << endl;

    // Create another instance of ArrayStack named stack2
    //   using the other constructor, specify an original size of 5
    // Push 1.0, 2.0, ..., 10.0 in this stack
    ArrayStack stack2 = ArrayStack(5);
    stack2.push(1.0);
    stack2.push(2.0);
    stack2.push(3.0);
   stack2.push(4.0);
   stack2.push(5.0);
    stack2.push(6.0);
    stack2.push(7.0);
    stack2.push(8.0);
    stack2.push(9.0);
    stack2.push(10.0);
    //     stack2.pop();
    // cout << stack2.top() << endl;
    //     stack2.pop();
    //     stack2.pop();
    //     stack2.pop();
    //     stack2.pop();
    //     stack2.pop();
    //     stack2.pop();
    //     stack2.pop();
    // cout << stack2.top() << endl;


       // Copy
       ArrayStack stack3(stack1);
       ArrayStack stack4 = stack2;
           // Assignment
       ArrayStack stack5;
       stack5 = stack1;
       ArrayStack stack6(10);
       stack6 = stack6;

       stack1.pop();
       cout << stack1.top() << endl;
       stack3.pop();
       cout << stack3.top() << endl;
       stack4.pop();
       cout << stack4.top() << endl;

   

    return 0;
}