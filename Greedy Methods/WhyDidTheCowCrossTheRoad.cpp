/*
Why Did the Cow Cross the Road 
==============================

Farmer John's cows are trying to learn to cross the road effectively. 
Remembering the old "why did the chicken cross the road?" joke, they 
figure the chickens must be experts on crossing the road, and go off 
in search of chickens to help them.

As it turns out, chickens are very busy creatures and have limited 
time to help the cows. There are C chickens on the farm (1 <= C <=
20,000), conveniently numbered 1...C, and each chicken i is only 
willing to help a cow at precisely time T_i. The cows, never in a 
hurry, have more flexibility in their schedules. There are N cows 
on the farm (1 <= N <= 20,000), conveniently numbered 1...N, where 
cow j is able to cross the road between time A_j and time B_j. 
Figuring the "buddy system" is the best way to proceed, each cow j 
would ideally like to find a chicken i to help her cross the road; 
in order for their schedules to be compatible, i and j must satisfy 
A_j <= T_i <= B_j.

If each cow can be paired with at most one chicken and each chicken 
with at most one cow, please help compute the maximum number of 
cow-chicken pairs that can be constructed.

PROBLEM NAME: helpcross

INPUT FORMAT:

The first line of input contains C and N. The next C lines contain 
T_1...T_C, and the next N lines contain A_j and B_j (A_j <= B_j) for 
j=1...N. The A's, B's, and T's are all non-negative integers (not 
necessarily distinct) of size at most 1,000,000,000.

OUTPUT FORMAT:

Please compute the maximum possible number of cow-chicken pairs.

SAMPLE INPUT:

5 4
7
8
6
2
9
2 5
4 9
0 3
8 13

SAMPLE OUTPUT:

3
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct timeframe{
    int start, end;
};

struct chick{
    int timef;
    bool taken;
};

bool comp(timeframe a, timeframe b){
    return ((a.end-a.start)<(b.end-b.start));
}

bool comp2(chick a, chick b){
    return (a.timef < b.timef);
}

int main(){
    int ch, co;
    cin >> ch >> co;
    
    chick chickens[ch];
    timeframe cows[co];
    for (int i = 0; i < ch; i++){
        cin >> chickens[i].timef;
        chickens[i].taken = false;
    }
    for (int i = 0; i < co; i++){
        cin >> cows[i].start >> cows[i].end;
    }
    
    sort(chickens, chickens+ch, comp2);
    sort(cows, cows+co, comp);
    
    int count = 0;
    for (int i = 0; i < co; i++){
        for (int j = 0; j < ch; j++){
            if (!chickens[j].taken && (chickens[j].timef >= cows[i].start) && (chickens[j].timef <= cows[i].end)){
                chickens[j].taken = true;
                count++;
                break;
            }
        }
    }
    
    cout << count;
}