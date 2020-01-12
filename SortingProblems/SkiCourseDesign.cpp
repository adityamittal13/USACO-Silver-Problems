/*
Ski Course Design
=================

Farmer John has N hills on his farm (1 <= N <= 1,000), each with an
integer elevation in the range 0 .. 100.  In the winter, since there is
abundant snow on these hills, FJ routinely operates a ski training camp.

Unfortunately, FJ has just found out about a new tax that will be assessed
next year on farms used as ski training camps.  Upon careful reading of the
law, however, he discovers that the official definition of a ski camp
requires the difference between the highest and lowest hill on his property
to be strictly larger than 17.  Therefore, if he shortens his tallest hills
and adds mass to increase the height of his shorter hills, FJ can avoid
paying the tax as long as the new difference between the highest and lowest
hill is at most 17.  

If it costs x^2 units of money to change the height of a hill by x units,
what is the minimum amount of money FJ will need to pay?  FJ is only
willing to change the height of each hill by an integer amount.

PROBLEM NAME: skidesign

INPUT FORMAT:

* Line 1: The integer N.

* Lines 2..1+N: Each line contains the elevation of a single hill.

SAMPLE INPUT:

5
20
4
1
24
21

INPUT DETAILS:

FJ's farm has 5 hills, with elevations 1, 4, 20, 21, and 24.

OUTPUT FORMAT:

* Line 1: The minimum amount FJ needs to pay to modify the elevations
        of his hills so the difference between largest and smallest is
        at most 17 units.

SAMPLE OUTPUT:

18

OUTPUT DETAILS:

FJ keeps the hills of heights 4, 20, and 21 as they are.  He adds mass to the
hill of height 1, bringing it to height 4 (cost = 3^2 = 9).  He shortens
the hill of height 24 to height 21, also at a cost of 3^2 = 9.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
    
int main(){
    int n;
    cin >> n;
    
    int h[n];
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        
        h[i] = l;
    }
    
    sort(h, h+n);
    
    int diff = h[n-1] - h[0] - 17;
    int minimum = 100000000;
    
    for (int i = 0; i < diff; i++){
        int goalValS = h[0] + i;
        int goalValE = h[n-1] - diff + i;
        
        int diffS = 0;
        for (int j = 0; j < n; j++){
            if (h[j] < goalValS){
                diffS += abs(goalValS - h[j]);
            } else {
                break;
            }
        }
        
        int diffE = 0;
        for (int j = n-1; j >= 0; j--){
            if (h[j] > goalValE){
                diffE += abs(goalValE - h[j]);
            } else {
                break;
            }
        }
        
        int totalCost = pow(diffS, 2) +  pow(diffE, 2);
        
        minimum = min(minimum, totalCost);
    }
    
    cout << minimum;
}