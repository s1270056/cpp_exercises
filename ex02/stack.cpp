#include <iostream>
#include <string>
#include "stack.h"
using namespace std;


bool Stack::empty()
{
    if (_top == -1)
        return true;
    else
        return false;
}
bool Stack::full()
{
    if (_top == _max_size)
        return true;
    else
        return false;
}

int Stack::size()
{
    int a = _top + 1;
    return a;
}

void Stack::push(std::string moji)
{
    if (_top == _max_size)
        std::cerr << "error" << std::endl;
    else
    {
        _top++;
        _data[_top] = moji;
        
    }
}

void Stack::pop()
{
    if (_top == -1)
        std::cerr << "error" << std::endl;
    else
        _data[_top--];
}

std::string Stack::top()
{
    
    return _data[_top];
}