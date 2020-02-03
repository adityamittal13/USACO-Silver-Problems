/*
Election Time
=============

The cows are having their first election after overthrowing the
tyrannical Farmer John, and Bessie is one of N cows (1 <= N <=
50,000) running for President. Before the election actually happens,
however, Bessie wants to determine who has the best chance of
winning.

The election consists of two rounds. In the first round, the K cows
(1 <= K <= N) cows with the most votes advance to the second round.
In the second round, the cow with the most votes becomes President.

Given that cow i expects to get A_i votes (1 <= A_i <= 1,000,000,000)
in the first round and B_i votes (1 <= B_i <= 1,000,000,000) in the
second round (if he or she makes it), determine which cow is expected
to win the election. Happily for you, no vote count appears twice
in the A_i list; likewise, no vote count appears twice in the B_i
list.

PROBLEM NAME: elect

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..N+1: Line i+1 contains two space-separated integers: A_i
        and B_i

SAMPLE INPUT:

5 3
3 10
9 2
5 6
8 4
6 5

INPUT DETAILS:

There are 5 cows, 3 of which will advance to the second round. The cows
expect to get 3, 9, 5, 8, and 6 votes, respectively, in the first round and
10, 2, 6, 4, and 5 votes, respectively, in the second.

OUTPUT FORMAT:

* Line 1: The index of the cow that is expected to win the election.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

Cows 2, 4, and 5 advance to the second round; cow 5 gets 5 votes in the
second round, winning the election.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct elect{
    int first, second, origi;
};

bool comp(elect a, elect b){
    return a.first > b.first;
}

bool comp2(elect a, elect b){
    return a.second > b.second;
}

int main(){
    int n, k;
    cin >> n >> k;
    
    elect cows[n];
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
        cows[i].origi = i;
    }
    
    sort(cows, cows+n, comp);
    
    elect cows2[k];
    
    for (int i = 0; i < k; i++){
        cows2[i] = {cows[i].first, cows[i].second, cows[i].origi};
    }
    
    sort(cows2, cows2+k, comp2);
    
    cout << cows2[0].origi+1;
}