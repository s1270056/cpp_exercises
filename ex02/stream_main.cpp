#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

int main()
{
    Stack stack2;
    std::string x;
    int y, z, i;
    std::ifstream ifs("data.txt");
    getline(ifs, x);
    z = stoi(x)+1;
    std::string str[z];
    str[0] = " ";
    y = str[0].length();

    for (i = 1; i < z; i++)
    {
        getline(ifs, str[i]);
        stack2.push(str[i]);
        if (str[i].length() > str[i - 1].length())
        {
            y = str[i].length();
        }
    }

    cout.width(y + 2);
    cout.fill('-');
    cout << '\n';

    for (i = 1; i < z; i++)
    {
        cout << stack2.top() << endl;
        stack2.pop();
    }
    cout.width(y + 2);
    cout.fill('-');
    cout << '\n';

    return 0;
}