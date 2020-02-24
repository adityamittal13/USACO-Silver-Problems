/*
Counting Haybales
=================

Farmer John has just arranged his N haybales (1 <= N <= 100,000) at 
various points along the one-dimensional road running across his 
farm. To make sure they are spaced out appropriately, please help him 
answer Q queries (1 <= Q <= 100,000), each asking for the number of 
haybales within a specific interval along the road.

PROBLEM NAME: haybales2

INPUT FORMAT:

The first line contains N and Q.

The next line contains N distinct integers, each in the range 
0...1,000,000,000, indicating that there is a haybale at each of 
those locations.

Each of the next Q lines contains two integers A and B (0 <= A <= B 
<= 1,000,000,000) giving a query for the number of haybales between A 
and B, inclusive.

OUTPUT FORMAT:

You should write Q lines of output. For each query, output the number 
of haybales in its respective interval.

SAMPLE INPUT:

4 6
3 2 7 5
2 3
2 4
2 5
2 7
4 6
8 10

SAMPLE OUTPUT:

2
2
3
4
1
0
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    
    int haybales[n];
    for (int i = 0; i < n; i++){
        cin >> haybales[i];
    }
    
    sort(haybales, haybales+n);
    
    for (int i = 0; i < q; i++){
        int start, end;
        cin >> start >> end;
        
        int count = 0;
        for (int j = 0; j < n; j++){
            if (haybales[j] >= start && haybales[j] <= end){
                count++;
            } else if (haybales[j] >= start)
                break;
        }
        
        cout << count << endl;
    }
}