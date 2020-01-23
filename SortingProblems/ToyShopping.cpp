/*
Toy Shopping
============

Bessie wants some toys. She's been saving her allowance for years,
and has an incredibly huge stash. However, she is quite frugal and
wants to get the best value for her cash. In fact, she has decided
only to buy exactly three different toys of the N (3 <= N <= 25,000)
offered at the Bovine Plaything Palace.

Toy i brings Bessie J_i (0 <= J_i <= 1,000,000) microbundles of joy
and has price P_i (0 < P_i <= 100,000,000). Bessie has enough money
to buy any three toys that she chooses.

Bessie wants to maximize the sum of her happy-frugal metric (which
is calculated as J_i/P_i -- joy divided by price) for the three
toys she chooses. Help Bessie decide which toys she should buy.
The answer is guaranteed to be unique.

Assume that the Bovine Plaything Palace offers 6 different toys for
Bessie:

        i    Joy       Price       Happy-Frugal Metric
        -    ---       -----       -------------------
        1      0        521               0.00000
        2    442        210               2.10476...
        3    119        100               1.19000
        4    120        108               1.11111...
        5    619        744               0.83198...
        6     48         10               4.80000

Bessie would choose toy 6 (HFM = 4.80), toy 2 (HFM = 2.10), and toy
3 (HFM = 1.19).

PROBLEM NAME: toyshop

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains two space-separated integers: J_i
        and P_i

SAMPLE INPUT:

6
0 521
442 210
119 100
120 108
619 744
48 10

OUTPUT FORMAT:

* Line 1: The total price that Bessie will have to pay

* Lines 2..4: In descending order sorted by the happy-frugal metric,
        the 1-based index of the toys that Bessie should buy, one per
        line

SAMPLE OUTPUT:

320
6
2
3
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
    double val;
    int index, price;
};

bool comp(Point a, Point b){
    return a.val > b.val;
}

int main(){
    int n;
    cin >> n;
    
    Point arr[n];
    for (int i =0; i<n; i++){
        double joy, price;
        cin >> joy >> price;
 
 
        arr[i].val = joy/price;
        arr[i].price = price;
        arr[i].index = i+1;
    }
    
    sort(arr, arr+n, comp);
    for (int i =0; i < n; i++){
        //cout << arr[i].val << " " << arr[i].price << " " << arr[i].index << endl;
    }
    
    cout << arr[0].price + arr[1].price + arr[2].price << endl;
    cout << arr[0].index<< endl;
    cout << arr[1].index << endl;
    cout << arr[2].index << endl;
}