/*
Calf Flac
=========

It is said that if you give an infinite number of cows an infinite 
number of heavy-duty laptops (with very large keys), that they will 
ultimately produce all the world's great palindromes. Your job will 
be to detect these bovine beauties.

Ignore punctuation, whitespace, numbers, and case when testing for 
palindromes, but keep these extra characters around so that you can 
print them out as the answer; just consider the letters 'A-Z' and 
'a-z'.

Find any largest palindrome in a string no more than 20,000 
characters long. The largest palindrome is guaranteed to be at most 
2,000 characters long before whitespace and punctuation are removed.

PROGRAM NAME: calfflac

INPUT FORMAT:

A file with no more than 20,000 characters. The file has one or 
more lines. No line is longer than 80 characters (not counting the 
newline at the end).

SAMPLE INPUT:

Confucius say: Madam, I'm Adam.

OUTPUT FORMAT:

The first line of the output should be the length of the longest 
palindrome found. The next line or lines should be the actual text 
of the palindrome (without any surrounding white space or 
punctuation but with all other characters) printed on a line (or 
more than one line if newlines are included in the palindromic 
text). If there are multiple palindromes of longest length, output 
the one that appears first.

SAMPLE OUTPUT:

11
Madam, I'm Adam
*/

#include <iostream>
#include <string>
using namespace std;

bool isAlphabet(char a){
    return ((int(a) >= 65) && (int(a) <= 90)) || ((int(a) >= 97) && (int(a) <= 122));
}

int length(string a){
    int l = 0;
    
    for (int i = 0; i < a.length(); i++){
        if (isAlphabet(a[i]))
            l++;
    }
    
    return l;
}

int main(){
    string val;
    string c;
    
    while (getline(cin, c)){
        val += c + "`";
    }
    
    int maxlen = 0;
    string maxstring = "";
    
    for (int i = 0; i < val.length(); i++){
        for (int j = i+1; j < val.length(); j++){
            bool same = (tolower(val[i]) == tolower(val[j]));
            bool sameDiff = (tolower(val[i]) == tolower(val[j+1]));
            bool sameA = (isAlphabet(val[i]));
            if (j < val.length()-1){
                if (sameDiff && sameA)
                    continue;
            }
            if (same && sameA){
                string value = val.substr(i, abs(j-i)+1);
                int lenV = length(value);
                if (lenV > maxlen){
                    int ival = 0;
                    int jval = value.length()-1;
                    bool palindrome = true;
                    while (palindrome){
                        ival++;
                        while ((ival != jval) && (abs(jval - ival) != 1) && !isAlphabet(value[ival]))
                            ival++;
                        
                        jval--;
                        while ((ival != jval) && (abs(jval - ival) != 1) && !isAlphabet(value[jval]))
                            jval--;
                        
                        //cout << value[ival] << " " << value[jval] << endl;
                        if ((tolower(value[ival]) != tolower(value[jval])) && (isAlphabet(value[ival])) && (isAlphabet(value[jval]))){
                            palindrome = false;
                            continue;
                        }
                        
                        if ((ival == jval) || (abs(ival - jval) == 1)) {
                            palindrome = true;
                            break;
                        }
                    }
                    
                    if (palindrome) {
                        maxlen = lenV;
                        maxstring = value;
                    }
                }
            }
        }
    }
    
    cout << maxlen << endl;
    for (int i = 0; i < maxstring.length(); i++){
        if (maxstring[i] == '`')
            cout << endl;
        else
            cout << maxstring[i];
    }
}