#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "palindrome.h"

int main() {
    string str1 = "Don't dog";
    string str2 = "Nurses run!";
    string str3 = "Don't worry.";
    string str4 = "Borrow or rob?";
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << "" << endl;

    if(isPalindrome(str1)== true)
    cout <<"\"" << str1 << "\"" << " is a palindrome" << endl;
    else
    cout <<"\"" << str1 << "\"" << " is not a palindrome" << endl;

    if(isPalindrome(str2)== true)
    cout <<"\"" << str2 << "\"" << " is a palindrome" << endl;
    else
    cout <<"\"" << str2 << "\"" << " is not a palindrome" << endl;

    if(isPalindrome(str3)== true)
    cout <<"\"" << str3 << "\"" << " is a palindrome" << endl;
    else
    cout <<"\"" << str3 << "\"" << " is not a palindrome" << endl;

    if(isPalindrome(str4)== true)
    cout <<"\"" << str4 << "\"" << " is a palindrome" << endl;
    else
    cout <<"\"" << str4 << "\"" << " is not a palindrome" << endl;

    return 0;
}