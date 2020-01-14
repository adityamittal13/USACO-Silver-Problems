/*
Bookshelf
=========

Farmer John recently bought a bookshelf for cow library, but the
shelf is getting filled up quite quickly, and now the only available
space is at the top.

Each of the N cows (1 <= N <= 20,000) has some height of H_i (1 <=
H_i <= 10,000) and a total height summed across all N cows of S.
The bookshelf has a height of B (1 <= B <= S < 2,000,000,007).

To reach the top of the bookshelf taller than the tallest cow, one
or more of the cows can stand on top of each other in a stack, so
that their total height is the sum of each of their individual
heights. This total height must be no less than the height of the
bookshelf. Since more cows than necessary in the stack can be
dangerous, your job is to find the set of cows that produces a stack
of the smallest number of cows possible such that the stack can
reach the bookshelf.

PROBLEM NAME: shelf

INPUT FORMAT:

* Line 1: Two space-separated integers: N and B

* Lines 2..N+1: Line i+1 contains a single integer: H_i

SAMPLE INPUT:

6 40
6
18
11
13
19
11

INPUT DETAILS:

Six cows; bookshelf height 40. Cow heights fall in the range 6..19.

OUTPUT FORMAT:

* Line 1: A single integer representing the size of the smallest set
        of cows that can reach the bookshelf.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

One way to reach 40 with 3 cows is 18+11+13; many others exist
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, h;
    cin >> n >> h;
    
    int arr[n];
    for (int i = 0; i < n; i++){
        int l;
        cin >> l;
        
        arr[i] = l;
    }
    
    sort (arr, arr+n);
    int minh = 1000000;
    
    for (int i = 0; i < pow(2, n)-1; i++){
        int val = i;
        int sum = 0;
        int numOfCows = 0;
        for (int j = n-1; j >= 0; j--){
            if (val >= pow(2, j)){
                val -= pow(2,j);
                sum += arr[j];
                numOfCows++;
            }
        }
        //cout << i << " " << sum << " " << numOfCows << endl;
        
        if (sum-h > 0)
            minh = min(numOfCows, minh);
    }
    
    cout << minh;
}