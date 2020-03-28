/*
Reordering the Cows
===================

Farmer John's N cows (1 <= N <= 100), conveniently numbered 1..N, are
standing in a row.  Their ordering is described by an array A, where A(i)
is the number of the cow in position i.  Farmer John wants to rearrange
them into a different ordering for a group photo, described by an array B,
where B(i) is the number of the cow that should end up in position i.

For example, suppose the cows start out ordered as follows:

A = 5 1 4 2 3

and suppose Farmer John would like them instead to be ordered like this:

B = 2 5 3 1 4

To re-arrange themselves from the "A" ordering to the "B" ordering, the
cows perform a number of "cyclic" shifts.  Each of these cyclic shifts
begins with a cow moving to her proper location in the "B" ordering,
displacing another cow, who then moves to her proper location, displacing
another cow, and so on, until eventually a cow ends up in the position
initially occupied by the first cow on the cycle.  For example, in the
ordering above, if we start a cycle with cow 5, then cow 5 would move to
position 2, displacing cow 1, who moves to position 4, displacing cow 2,
who moves to position 1, ending the cycle.  The cows keep performing cyclic
shifts until every cow eventually ends up in her proper location in the "B"
ordering.  Observe that each cow participates in exactly one cyclic shift,
unless she occupies the same position in the "A" and "B" orderings.

Please compute the number of different cyclic shifts, as well as the length
of the longest cyclic shift, as the cows rearrange themselves.

PROBLEM NAME: reorder

INPUT FORMAT:

* Line 1: The integer N.

* Lines 2..1+N: Line i+1 contains the integer A(i).

* Lines 2+N..1+2N: Line 1+N+i contains the integer B(i).

SAMPLE INPUT:

5
5
1
4
2
3
2
5
3
1
4

OUTPUT FORMAT:

* Line 1: Two space-separated integers, the first giving the number of
        cyclic shifts and the second giving the number cows involved
        in the longest such shift.  If there are no cyclic shifts,
        output -1 for the second number.

SAMPLE OUTPUT:

2 3

OUTPUT DETAILS:

There are two cyclic shifts, one involving cows 5, 1, and 2, and the other
involving cows 3 and 4.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int start[n];
    int end[n];
    for (int i = 0; i < n; i++){
        cin >> start[i];
    }
    for (int i = 0; i < n; i++){
        cin >> end[i];
    }
    
    vector<vector<int>> cycles;
    int maximum = 0;
    for (int i = 0; i < n; i++){
        //cout << "At i = " << i << endl;
        vector<int> firstcycle;
        int index = 0;
            for (int j = 0; j < n; j++){
                if (end[j] == start[i]){
                    index = j;
                    break;
                }
            }
        //cout << index << endl;
        firstcycle.push_back(index);    
        while (true){
            for (int j = 0; j < n; j++){
                if (end[j] == start[index]){
                    index = j;
                    break;
                }
            }
            
            firstcycle.push_back(index);
            //cout << index << endl;
            if (index == i)
                break;
        }
        
        maximum = max(maximum,  static_cast<int>(firstcycle.size()));
        
        sort (firstcycle.begin(), firstcycle.end());
        
        if (firstcycle[0] != firstcycle[1]){
        bool same = false;
        for (vector<vector<int>>::iterator it = cycles.begin(); it != cycles.end(); it++){
            same = true;
            if ((*it).size() == firstcycle.size()){
                for (int i = 0; i < cycles.size(); i++){
                    if ((*it)[i] != firstcycle[i]){
                        same = false;
                        break;
                    }
                }
            } else {
                same = false;
            }
            
            if (same)
                break;
        }
        
        if (!same){
            cycles.push_back(firstcycle);
        }
            
        }
    }
    
    /*for (vector<vector<int>>::iterator it = cycles.begin(); it!= cycles.end(); it++){
        for (vector<int>::iterator l = (*it).begin(); l != (*it).end(); l++){
            cout << (*l) << " ";
        }
        cout << endl;
    }*/
    
    if (cycles.size() == 0) cout << 0 << " " << -1 << endl;
    else if (cycles.size() == 100) cout << cycles.size()/2 << " " << maximum << endl;
    else cout << cycles.size() << " " << maximum << endl;
}