/*
Registers in the Shop
=====================

Bessie likes shopping at CowMart. She is also curious about the
payment system at the registers. There are less than 1,000
customers in the store. When a customer want to pay, she goes to the
the end of the line. When a register is available,the next customer
in front of the line goes to the register and pays. Bessie would
like to know which customers payed at which register at the end of
the day. Initially there are no customers in the store. A customer
can pay then buy something again. In that case, the customer
has to enter the line at the end again. The number of registers
in the store is 0 < N <= 30.

As an example, there are 5 customers and 3 registers
in the store. The sequence of available registers and customers to
enter the line is given as follows:

Process   Line      Register 1  Register 2  Register 3
=======   ====      ==========  ==========  ==========
C 1       1
C 5       1 5
C 3       1 5 3
R 3       5 3                               1
C 2       5 3 2                             1
R 3       3 2                               1 5
C 5       3 2 5                             1 5
R 2       2 5                   3           1 5
C 4       2 5 4                 3           1 5
C 1       2 5 4 1               3           1 5
R 3       5 4 1                 3           1 5 2
C 3       5 4 1 3               3           1 5 2
R 2       4 1 3                 3 5         1 5 2
R 1       1 3       4           3 5         1 5 2
C 5       1 3 5     4           3 5         1 5 2
C 2       1 3 5 2   4           3 5         1 5 2
R 2       3 5 2     4           3 5 1       1 5 2
R 2       5 2       4           3 5 1 3     1 5 2
R 1       2         4 5         3 5 1 3     1 5 2
R 1                 4 5 2       3 5 1 3     1 5 2

Here 'C' corresponds to the customer and 'R' corresponds to the register.
Then the list of the customers payed at the registers are as follows:

Register 1: 4 5 2
Register 2: 3 5 1 3
Register 3: 1 5 2


PROBLEM NAME: shoppay

INPUT FORMAT:
* Line 1: N, the number of registers in the store.

* Line 2..end-of-file: Each line is ither C then followed by customer number
or R then followed by register number. Number of lines is less than 10,000.

SAMPLE INPUT:

3
C 1
C 5
C 3
R 3
C 2
R 3
C 5
R 2
C 4
C 1
R 3
C 3
R 2
R 1
C 5
C 2
R 2
R 2
R 1
R 1

OUTPUT FORMAT:

* Line 1..N: Line i has R_i, the number of customers in that register,
then R_i numbers corresponding to the list of the customers payed at register i
ordered from the earliest to latest.

SAMPLE OUTPUT:

3 4 5 2
4 3 5 1 3
3 1 5 2
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> arr[n];
    vector<int> v;
    
    char l; int r;
    while (cin >> l >> r){
        if (l == 'C'){
            v.push_back(r);
        } else if (l == 'R'){
            int num = v.front();
            arr[r-1].push_back(num);
            v.erase(v.begin());
        }
    }
    
    for (auto i: arr){
        cout << i.size() << " ";
        for (auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}