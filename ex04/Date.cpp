#include <iostream>
#include "Date.h"
using namespace std;

void Date::set(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void Date::print() {
    cout << year << "年 " << month << "月 " << day << "日\n";
}

int Date::get_month() {
    return month;
}

int Date::get_year() {
    return year;
}

int Date::get_day() {
    return day;
}

void Date::inc_day() {
    day++;
    if(month == 2 && day == 30){
        day = 1;
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month ==11 && day == 31){
        day = 1;
    }
    else if(day == 32){
        day = 1;
    }
}

void Date::inc_month() {
    month++;
    if(month == 13) month = 1;
}

void Date::inc_year() {
    year++;
}