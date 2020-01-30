/*
Binary Search
=============

Implement a binary search algorithm that returns the index of the
first occurrence of a number K, or -1 if it could not be found. You
will be supplied with a (sorted) list of N numbers (0 <= N <= 100,000).

For example, suppose you were given the following (sorted) array as
input.

2 3 4 4 9 11 12

Searching for 4 should return 2, searching for 9 should return 4, and
searching for 10 should return -1.

You will be asked to answer Q queries (1 <= Q <= 100,000), each of which
is a single number and should be answered as stated above.

PROBLEM NAME: binarysearch

INPUT FORMAT:

* Line 1: Two integers, N and Q.

* Line 2: N sorted integers. 

* Lines 3..Q+2: A single integer K on each line, representing a query.

SAMPLE INPUT:

7 2
2 3 4 4 9 11 12
9
10

OUTPUT FORMAT:

* Lines 1..Q: The index of the first occurrence of K in the supplied array,
        or -1 if not found.

SAMPLE OUTPUT:

4
-1

OUTPUT DETAILS:

The index of 9 is 4, and 10 is not in the array so the function returns -1.
*/

#include <iostream>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    
    int list[n];
    for (int i = 0; i < n; i++){
        cin >> list[i];
    }
    
    for (int i = 0; i < q; i++){
        int query;
        cin >> query;
        
        bool found = false;
        
        int m = list[n/2];
        int l = list[0];
        int r = list[n-1];
        int li = 0;
        int ri = n-1;
        int mi = n/2;
        
        while ((l != r) && (li != (ri-1)) && (li != (ri+1))){
            if (query > m){
                l = m;
                li = mi;
            } else if (query < m) {
                r = m;
                ri = mi;
            } else if (query == m) {
                int index = mi;
                for (int j = mi; j > 0; j--){
                    if (list[j] == list[j-1])
                        index = j - 1;
                    else
                        break;
                }
                cout << index << endl;
                found = true;
                break;
            }
            m = list[(li + ri)/2];
            mi = (li + ri)/2;
        }
        
        if ((list[li] == query) && !found) {
            found = true;
            cout << li << endl;
        } else if ((list[ri] == query) && !found) {
            found = true;
            cout << ri << endl;
        }
        
        if (!found){
            cout << -1 << endl;
        }
    }
}