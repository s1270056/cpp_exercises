#ifndef Palindrome_H
#define Palindrome_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string& str){
    string s1=str;
    string s2=str;

    transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char ss) { return tolower(ss); });
    transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char ss) { return tolower(ss); });

    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), ','), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '\''), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '.'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '\"'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '!'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '?'), s1.end());


    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
    s2.erase(remove(s2.begin(), s2.end(), ','), s2.end());
    s2.erase(remove(s2.begin(), s2.end(), '\''), s2.end());
    s2.erase(remove(s2.begin(), s2.end(), '.'), s2.end());
    s2.erase(remove(s2.begin(), s2.end(), '\"'), s2.end());
    s2.erase(remove(s2.begin(), s2.end(), '!'), s2.end());
    s2.erase(remove(s2.begin(), s2.end(), '?'), s2.end());

    if (equal(s1.begin(), s1.begin() + s1.size() / 2, s2.rbegin())) {
        return true;
    }
    else {
        return false;
    }

}

#endif