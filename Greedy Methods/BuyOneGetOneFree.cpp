/*
Buy One Get One Free
====================

Farmer John has discovered the Internet is buying bales of hay
online when he notices a special deal. For every bale of hay of
size A (1 <= A <= 1,000,000) he buys, he can get a bale of hay of
size B (1 <= B < A) for free!

The deal, however, is restricted: the larger bale must be high
quality hay and the smaller one must be low quality hay. FJ, being
a frugal and thrifty fellow, does not care: any quality of hay will
do as long as he saves some money.

Given a list of the sizes of N (1 <= N <= 10,000) bales of high
quality hay and M (1 <= M <= 10,000) bales of low quality hay, find
the maximum number of bales of hay Farmer John can purchase.  He
can buy bales of high quality hay without getting the free bale of
low quality hay, but he cannot buy bales of low quality hay (i.e.,
he must get them for free in the deal).

PROBLEM NAME: buyfree

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M.

* Lines 2..N+1: Line i+1 contains a single integer which is the size
        of the ith bale of high quality hay.

* Lines N+2..N+M+1: Line i+N+1 contains a single integer which is the
        size of the ith bale of low quality hay.

SAMPLE INPUT:

3 4
6
1
3
1
5
3
4

INPUT DETAILS:

There are 3 bales of high quality hay, with sizes 6, 1, and 3, and 4 bales
of low quality hay, with sizes 1, 5, 3, and 4.

OUTPUT FORMAT:

* Line 1: The maximum total number of bales of hay Farmer John can
        obtain.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

Obviously, Farmer John can buy all the bales of high quality hay.
When he buys the size 6 high quality bale, he can get any low quality
bale for free (say, the bale of size 3). When he buys the size 3
high quality bale, he can get the size 1 low quality bale for free.
When he buys the size 1 high quality bale, however, he cannot get
any low quality bales for free (since the size must be strictly
less). The total, no matter how clever FJ is, comes to five bales.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    int high[n];
    int low[m];
    
    for (int i = 0; i < n; i++){
        cin >> high[i];
    }
    for (int i = 0; i < m; i++){
        cin >> low[i];
    }
    
    sort(high, high+n);
    sort(low, low+m);
    
    int count = 0;
    for (int i = 0; i < n; i++){
        count++;
        int maxi = 0;
        int index = 0;
        for (int j = 0; j < m; j++){
            if (high[i] > low[j]){
                maxi = max(maxi, low[j]);
                if (maxi == low[j])
                    index = j;
            }
        }
        
        if (maxi > 0){
            count++;
            low[index] = -1;
        }
    }
    
    cout << count;
}