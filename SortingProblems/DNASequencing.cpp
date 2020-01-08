/*
DNA Sequencing
==============

Farmer John is studying the geneology of his herd. He has M bulls
(1 <= M <= 20) and F cows (1 <= F <= 20). He doesn't know, though,
which bovines are potential descendants of which other bovines.

Farmer John does know the unique DNA sequence DNA_i of each and
every cow and bull on his farm. DNA_i has length 25 characters and
contains only upper-case letters 'A', 'C', 'G', and 'T'. He wants
to determine which bovines could possibly be children of which pairs
of cows and bulls.

Help Farmer John make this determination. For each pair of a cow
and a bull, print how many of FJ's other bovines could possibly be
their children. A bovine can be a child of a given cow and bull if

    (1) it is not either of its parents (that is, a cow cannot be
        its own mother and a bull cannot be its own father)
    (2) each position in its DNA sequence matches at least one of
	the characters in the same position in the two parent
	sequences

So for example, 'abc' could come from pair ('axx', 'xbc'), but not
from the pair ('aaa', 'bbb').

Consider three bulls and two cows with these DNA sequences:

       Bull 1: GTTTTTTTTTTTTTTTTTTTTTTTT
       Bull 2: AATTTTTTTTTTTTTTTTTTTTTTT
       Bull 3: GATTTTTTTTTTTTTTTTTTTTTTT
       Cow 1:  TTTTTTTTTTTTTTTTTTTTTTTTT
       Cow 2:  ATTTTTTTTTTTTTTTTTTTTTTTT

Bull 2 and cow 1 could be the parents of cow 2:
       Bull 2: AATTTTTTTTTTTTTTTTTTTTTTT
       Cow 1:  TTTTTTTTTTTTTTTTTTTTTTTTT
       Cow 2:  ATTTTTTTTTTTTTTTTTTTTTTTT
since cow 2's first letter 'A' could be from Bull 2; cow 2's second
letter 'T' could come from cow 1; the remainder of the letters could
come from either parent.

Your goal is to create a matrix of the count of possible offspring
of each pairing of bulls and cows. 

PROBLEM NAME: dna

INPUT FORMAT:

* Line 1: Two space-separated integers: M and F

* Lines 2..M+1: Line i+1 gives the DNA sequence of bull i: DNA_i

* Lines M+2..M+F+1: Line j+M+1 gives the DNA sequence of cow j: DNA_j

SAMPLE INPUT:

2 3
TGAAAAAAAAAAAAAAAAAAAAAAA
AGAAAAAAAAAAAAAAAAAAAAAAA
ATAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAA
TTAAAAAAAAAAAAAAAAAAAAAAA

INPUT DETAILS:

Two bulls' DNA followed by three cows' DNA

OUTPUT FORMAT:

* Lines 1..M: Line i: F space-separated integers. The jth integer is
        the number of bovines that could be children of the ith bull
        and jth cow.

SAMPLE OUTPUT:

2 1 0
0 0 2

OUTPUT DETAILS:

Consider bull 1 and cow 1:

    b1: TGAAAAAAAAAAAAAAAAAAAAAAA
    c1: ATAAAAAAAAAAAAAAAAAAAAAAA

One might express the important part of their DNA as {T|A} followed
by {G|T}

Here's the 'matching' tests for bull 0 and cow 0:

    b1: TGAAAAAAAAAAAAAAAAAAAAAAA -- parent, can't be offspring
    b2: AGAAAAAAAAAAAAAAAAAAAAAAA offspring! Matches [TA][GT]
    c1: ATAAAAAAAAAAAAAAAAAAAAAAA -- parent, can't be offspring
    c2: AAAAAAAAAAAAAAAAAAAAAAAAA -- second character is 'A'; must be G or T
    c3: TTAAAAAAAAAAAAAAAAAAAAAAA offspring! Matches [TA][GT]

Thus, the first element of the result matrix is 2. Other elements
derived similarly.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int b, c;
    cin >> b >> c;
    
    string arr[b+c];
    for (int i = 0; i < b+c; i++){
        string j;
        cin >> j;
        
        arr[i] = j;
        //cout << i << " " << arr[i] << endl;
    }
    //cout << endl;
    
    for (int i = 0; i < b; i++){
        for (int j = 0; j < c; j++){
            string bull = arr[i];
            string cow = arr[b+j];
            
            int count = 0;
            for (int k = 0; k < b+c; k++){
                if (k != i && k != b+j){
                    bool val = true;
                    for (int l = 0; l < bull.length(); l++){
                        if (bull[l] != arr[k][l] && arr[k][l] != cow[l]){
                            val = false;
                            break;
                        }
                    }
                    if (val)
                        count++;
                        //cout << arr[k] << " " << k <<  endl;}
                }
            }
            
            cout << count << " ";//<< " " << i << " " << b+j << endl;
        }
        cout << endl;
    }
}