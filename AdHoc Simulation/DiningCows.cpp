/*
Dining Cows
===========

The cows are so very silly about their dinner partners. They have
organized themselves into two groups (conveniently numbered 1 and
2) that insist upon dining together in order, with group 1 at the
beginning of the line and group 2 at the end. The trouble starts
when they line up at the barn to enter the feeding area.

Each cow i carries with her a small card upon which is engraved D_i
(1 <= D_i <= 2) indicating her dining group membership. The entire
set of N (1 <= N <= 30,000) cows has lined up for dinner but it's
easy for anyone to see that they are not grouped by their dinner-partner
cards.

FJ's job is not so difficult.  He just walks down the line of cows
changing their dinner partner assignment by marking out the old
number and writing in a new one. By doing so, he creates groups of
cows like 112222 or 111122 where the cows' dining groups are sorted
in ascending order by their dinner cards. Rarely he might change
cards so that only one group of cows is left (e.g., 1111 or 222).

FJ is just as lazy as the next fellow. He's curious: what is the
absolute minimum number of cards he must change to create a proper
grouping of dining partners? He must only change card numbers and
must not rearrange the cows standing in line.

PROBLEM NAME: diningb

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 describes cow i's dining preference with a
        single integer: D_i

SAMPLE INPUT:

7
2
1
1
1
2
2
1

INPUT DETAILS:

Seven cows; all but three of which currently prefer dining group 1.

OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of cards Farmer
        John must change to assign the cows to eating groups as
        described.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

Change the first and last cow's cards.
*/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_INT 100000

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int minimum = MAX_INT;
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j <= i; j++){
            if (arr[j] == 2)
                count++;
        }
        for (int j = i+1; j < n; j++){
            if (arr[j] == 1)
                count++;
        }
        
        minimum = min(minimum, count);
    }
    
    bool all2s = true;
    for (int i = 0; i < n; i++){
        if (arr[i] == 1){
            all2s = false;
            break;
        }
    }
    
    if (!all2s)
        cout << minimum;
    else
        cout << 0;
}