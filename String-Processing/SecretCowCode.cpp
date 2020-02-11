/*
Secret Cow Code
===============

The cows are experimenting with secret codes, and have devised a 
method for creating an infinite-length string to be used as part of 
one of their codes.

Given a string s, let F(s) be s followed by s "rotated" one character 
to the right (in a right rotation, the last character of s rotates 
around and becomes the new first character). Given an initial string 
s, the cows build their infinite-length code string by repeatedly 
applying F; each step therefore doubles the length of the current 
string.

Given the initial string and an index N, please help the cows compute 
the character at the N th position within the infinite code string.

PROBLEM NAME: cowcode

INPUT FORMAT:

The input consists of a single line containing a string followed by 
N. The string consists of at most 30 uppercase characters, and N <= 
10^18.

Note that N may be too large to fit into a standard 32-bit integer, 
so you may want to use a 64-bit integer type (e.g., a "long long" in 
C/C++).

OUTPUT FORMAT:

Please output the N th character of the infinite code built from the 
initial string. The first character is N=1.

SAMPLE INPUT:

COW 8

SAMPLE OUTPUT:

C

In this example, the initial string COW expands as follows:

COW -> COWWCO -> COWWCOOCOWWC
                 12345678

Problem credits: Brian Dean 
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string n; 
    long long num;
    cin >> n >> num;
    
    int length = n.length();
    int num2 = 0;
    while (length*pow(2, num2) < num){
        num2++;
    }
    
    while (num2 >= 0){
        if (num > (length*pow(2,num2-1)))
            num -= (length*pow(2,num2-1))+1;
        
        if (num == 0){
            num = (length*pow(2,num2-1));
        }
        
        num2--;
    }
    
    cout << n[num-1];
}