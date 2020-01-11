/*
Friday the Thirteenth
=====================

Is Friday the 13th really an unusual event?

That is, does the 13th of the month land on a Friday less often than on 
any other day of the week? To answer this question, write a program that 
will compute the frequency that the 13th of each month lands on 
Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday 
over a given period of N years. The time period to test will be from 
January 1, 1900 to December 31, 1900+N-1 for a given number of years, N. 
N is non-negative and will not exceed 400.

There are few facts you need to know before you can solve this problem:

    * January 1, 1900 was on a Monday.
    * Thirty days has September, April, June, and November, all the rest 
    have 31 except for February which has 28 except in leap years when it has 29.
    * Every year evenly divisible by 4 is a leap year 
    (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
    * The rule above does not hold for century years. Century years divisible 
    by 400 are leap years, all other are not. Thus, the century years 
    1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year. 

Do not use any built-in date functions in your computer language.

Don't just precompute the answers, either, please.

PROGRAM NAME: friday

INPUT FORMAT:

One line with the integer N.

SAMPLE INPUT:

20

OUTPUT FORMAT:

Seven space separated integers on one line. These integers represent the number 
of times the 13th falls on Saturday, Sunday, Monday, Tuesday, ..., Friday.

SAMPLE OUTPUT:

36 33 34 33 35 35 34

*/

#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                return true;
            }
        } else {
            return true;
        }
    }
    return false;
}

int numOfDays(string month, bool leap){
    if (month == "January"){
        return 31;
    }
    if (month == "February"){
        if (leap) 
            return 29;
        return 28;
    }
    if (month == "March"){
        return 31;
    }
    if (month == "April"){
        return 30;
    }
    if (month == "May"){
        return 31;
    }
    if (month == "June"){
        return 30;
    }
    if (month == "July"){
        return 31;
    }
    if (month == "August"){
        return 31;
    }
    if (month == "September"){
        return 30;
    }
    if (month == "October"){
        return 31;
    }
    if (month == "November"){
        return 30;
    }
    if (month == "December"){
        return 31;
    }
}

int main(){
    int n;
    cin >> n;
    
    int arr[7] = {0};
    int n1 = 2;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 12; j++){
            int num = numOfDays(months[j], isLeapYear(1900+i));
            for (int k = 1; k <= num; k++){
                if (k == 13){
                    arr[n1]++;
                    //cout << months[j] << endl;
                }
                if (n1 < 6){
                    n1++;
                } else {
                    n1 = 0;
                }
            }
        }
    }
    
    for (int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
}