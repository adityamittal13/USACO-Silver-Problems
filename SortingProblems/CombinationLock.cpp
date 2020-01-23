/*
Combination Lock
================

Farmer John's cows keep escaping from his farm and causing mischief. To try
and prevent them from leaving, he purchases a fancy combination lock to
keep his cows from opening the pasture gate. 

Knowing that his cows are quite clever, Farmer John wants to make sure they
cannot easily open the lock by simply trying many different combinations. 
The lock has three dials, each numbered 1..N (1 <= N <= 100), where 1 and N
are adjacent since the dials are circular.  There are two combinations that
open the lock, one set by Farmer John, and also a "master" combination set
by the lock maker.  The lock has a small tolerance for error, however, so
it will open even if the numbers on the dials are each within at most 2
positions of a valid combination.  For example, if Farmer John's
combination is (1,2,3) and the master combination is (4,5,6), the lock will
open if its dials are set to (1,N,5) (since this is close enough to Farmer
John's combination) or to (2,4,8) (since this is close enough to the master
combination).  Note that (1,5,6) would not open the lock, since it is not
close enough to any one single combination.

Given Farmer John's combination and the master combination, please
determine the number of distinct settings for the dials that will open the
lock.  Order matters, so the setting (1,2,3) is distinct from (3,2,1).

PROBLEM NAME: combo

INPUT FORMAT:

* Line 1: The integer N.

* Line 2: Three space-separated integers, specifying Farmer John's
        combination.

* Line 3: Three space-separated integers, specifying the master
        combination (possibly the same as Farmer John's combination).

SAMPLE INPUT:

50
1 2 3
5 6 7

INPUT DETAILS:

Each dial is numbered 1..50.  Farmer John's combination is (1,2,3), and the
master combination is (5,6,7).

OUTPUT FORMAT:

* Line 1: The number of distinct dial settings that will open the
        lock.

SAMPLE OUTPUT:

249
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int f[3];
    int m[3];
    for (int i = 0; i < 3; i++){
        cin >> f[i];
    }
    for (int i = 0; i < 3; i++){
        cin >> m[i];
    }
    
    int count = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                bool workComb = false;
                if (abs(m[0] - i) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k) <= 2)
                    workComb = true;
                if (abs(f[0] - i) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k) <= 2)
                    workComb = true;
                if (i == n || i == n-1 || j == n || j == n-1 || k == n || k == n-1) {
                    if (abs(m[0] - i + n) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k) <= 2)
                        workComb = true;
                    if (abs(f[0] - i + n) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k) <= 2)
                        workComb = true;
                    if (abs(m[0] - i) <= 2&&abs(m[1]-j+n) <= 2&&abs(m[2]-k) <= 2)
                        workComb = true;
                    if (abs(f[0] - i) <= 2&&abs(f[1]-j+n) <= 2&&abs(f[2]-k) <= 2)
                        workComb = true;
                    if (abs(m[0] - i) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(m[0] - i + n) <= 2&&abs(m[1]-j+n) <= 2&&abs(m[2]-k) <= 2)
                        workComb = true;
                    if (abs(f[0] - i + n) <= 2&&abs(f[1]-j+n) <= 2&&abs(f[2]-k) <= 2)
                        workComb = true;
                    if (abs(m[0] - i) <= 2&&abs(m[1]-j+n) <= 2&&abs(m[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i) <= 2&&abs(f[1]-j+n) <= 2&&abs(f[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(m[0] - i+n) <= 2&&abs(m[1]-j+n) <= 2&&abs(m[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i+n) <= 2&&abs(f[1]-j+n) <= 2&&abs(f[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(m[0] - i+n) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k+n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i+n) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k+n) <= 2)
                        workComb = true;
                }
                
                if (f[0] == n || f[0] == n-1 || f[1] == n || f[1] == n-1 || f[2] == n || f[2] == n-1) {
                    if (abs(f[0] - i - n) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k) <= 2)
                        workComb = true;
                    if (abs(f[0] - i) <= 2&&abs(f[1]-j-n) <= 2&&abs(f[2]-k) <= 2)
                        workComb = true;
                    if (abs(f[0] - i) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k-n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i-n) <= 2&&abs(f[1]-j-n) <= 2&&abs(f[2]-k) <= 2)
                        workComb = true;
                    if (abs(f[0] - i) <= 2&&abs(f[1]-j-n) <= 2&&abs(f[2]-k-n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i-n) <= 2&&abs(f[1]-j) <= 2&&abs(f[2]-k-n) <= 2)
                        workComb = true;
                    if (abs(f[0] - i-n) <= 2&&abs(f[1]-j-n) <= 2&&abs(f[2]-k-n) <= 2)
                        workComb = true;
                }
                
                if (m[0] == n || m[0] == n-1 || m[1] == n || m[1] == n-1 || m[2] == n || m[2] == n-1) {
                    if (abs(m[0] - i - n) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k) <= 2)
                        workComb = true;
                    if (abs(m[0] - i) <= 2&&abs(m[1]-j-n) <= 2&&abs(m[2]-k) <= 2)
                        workComb = true;
                    if (abs(m[0] - i) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k-n) <= 2)
                        workComb = true;
                    if (abs(m[0] - i-n) <= 2&&abs(m[1]-j-n) <= 2&&abs(m[2]-k) <= 2)
                        workComb = true;
                    if (abs(m[0] - i) <= 2&&abs(m[1]-j-n) <= 2&&abs(m[2]-k-n) <= 2)
                        workComb = true;
                    if (abs(m[0] - i-n) <= 2&&abs(m[1]-j) <= 2&&abs(m[2]-k-n) <= 2)
                        workComb = true;
                    if (abs(m[0] - i-n) <= 2&&abs(m[1]-j-n) <= 2&&abs(m[2]-k-n) <= 2)
                        workComb = true;
                }
                
                if (workComb)
                    count++;
            }
        }
    }
    cout << count;
}