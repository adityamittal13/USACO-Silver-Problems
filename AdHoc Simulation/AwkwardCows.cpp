/*
Awkward Digits
==============

Bessie the cow is just learning how to convert numbers between different
bases, but she keeps making errors since she cannot easily hold a pen
between her two front hooves.

Whenever Bessie converts a number to a new base and writes down the result,
she always writes one of the digits wrong.  For example, if she converts
the number 14 into binary (i.e., base 2), the correct result should be
"1110", but she might instead write down "0110" or "1111".  Bessie never
accidentally adds or deletes digits, so she might write down a number with
a leading digit of "0" if this is the digit she gets wrong.

Given Bessie's output when converting a number N into base 2 and base 3,
please determine the correct original value of N (in base 10). You can
assume N is at most 1 billion, and that there is a unique solution for N.

Please feel welcome to consult any on-line reference you wish regarding
base-2 and base-3 numbers, if these concepts are new to you.

PROBLEM NAME: digits

INPUT FORMAT:

* Line 1: The base-2 representation of N, with one digit written
        incorrectly.

* Line 2: The base-3 representation of N, with one digit written
        incorrectly.

SAMPLE INPUT:

1010
212

INPUT DETAILS:

When Bessie incorrectly converts N into base 2, she writes down
"1010".  When she incorrectly converts N into base 3, she writes down "212".

OUTPUT FORMAT:

* Line 1: The correct value of N.

SAMPLE OUTPUT:

14

OUTPUT DETAILS:

The correct value of N is 14 ("1110" in base 2, "112" in base 3).
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    string base2, base3;
    cin >> base2 >> base3;
    
    vector<int> basetwos;
    vector<int> basethrees;
    
    string twobase = base2;
    for (int i = 0; i < twobase.length(); i++){
        twobase = base2;
        
        if (twobase[i] == '1')
            twobase[i] = '0';
        else if(twobase[i] == '0')
            twobase[i] = '1';
        
        //cout << twobase << " ";
        
        int count = 0;
        for (int j = 0; j < twobase.length(); j++){
            if (twobase[j] == '1')
                count += pow(2, twobase.length()-1-j);
        }
        
        //cout << count << endl; 
        basetwos.push_back(count);
    }
    
    string threebase = base3;
    for (int i = 0; i < threebase.length(); i++){
        threebase = base3;
        
        if (threebase[i] == '1')
            threebase[i] = '2';
        else if (threebase[i] == '2')
            threebase[i] = '0';
        else if (threebase[i] == '0')
            threebase[i] = '1';
            
        int count = 0;
        for (int j = 0; j < threebase.length(); j++){
            if (threebase[j] == '1')
                count += pow(3, threebase.length()-1-j);
            if (threebase[j] == '2')
                count += pow(3, threebase.length()-1-j)*2;
        }
        
        basethrees.push_back(count);
    }
    
    threebase = base3;
    for (int i = 0; i < threebase.length(); i++){
        threebase = base3;
        
        if (threebase[i] == '1')
            threebase[i] = '0';
        else if (threebase[i] == '2')
            threebase[i] = '1';
        else if (threebase[i] == '0')
            threebase[i] = '2';
            
        int count = 0;
        for (int j = 0; j < threebase.length(); j++){
            if (threebase[j] == '1')
                count += pow(3, threebase.length()-1-j);
            if (threebase[j] == '2')
                count += pow(3, threebase.length()-1-j)*2;
        }
        
        basethrees.push_back(count);
    }
    
    for (vector<int>::iterator it = basetwos.begin(); it != basetwos.end(); it++){
        for (vector<int>:: iterator it2 = basethrees.begin(); it2 != basethrees.end(); it2++){
            //out << (*it) << " " << (*it2) << endl;
            if ((*it) == (*it2)){
                cout << (*it);
                break;
            }
        }
    }
}