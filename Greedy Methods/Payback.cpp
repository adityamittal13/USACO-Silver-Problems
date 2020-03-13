/*
Payback
=======

"Never a borrower nor a lender be." O how Bessie wishes she had 
taken that advice! She has borrowed from or lent money to each of 
N (1 <= N <= 100,000) friends, conveniently labeled 1..N.

Payback day has finally come. She knows she is owed more money than
she owes to the other cows. They have all lined up in a straight
line, cow i standing i meters from the barn. Bessie is going to
traverse the line collecting money from those who owe her and
reimbursing money to those she owes.

As she moves down the line, she can request any cow who owes her
money to give her the money. When she has enough money to pay off
any or all of her debts, she can pay the (recently collected) money
to those she owes. Cow i owes Bessie D_i money (-1,000 <= D_i <=
1,000; D_i != 0). A negative debt means that Bessie owes money to
the cow instead of vice-versa.

Bessie starts at the barn, location 0. What is the minimum distance
she must travel to collect her money and pay all those she owes? She
must end her travels at the end of the line.

PROBLEM NAME: iou

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: D_i

SAMPLE INPUT:

5
100
-200
250
-200
200

INPUT DETAILS:

Three cows owe Bessie; she owes two. When she's done, Bessie will 
have 150 money.

OUTPUT FORMAT:

* Line 1: A single integer that is the total metric distance Bessie
        must travel in order to collect or pay each cow.

SAMPLE OUTPUT:

9

OUTPUT DETAILS:

Barn  100  -200  250 -200  200
 |     |     |    |    |    |
 ***>**+**>*****>**+
                   *            < Bessie has 350
             -**<***
             *                  < Bessie has 150
             ***>****>****>**+
                             *  < Bessie has 350
                       -**<***
                       *     
                       ***>***  < Bessie ends her travels with 150*
*/

#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
   
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    queue<int> stack1;
    int totMoney = 0;
    int steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        bool isPushed = false;
        if (arr[i] >= 0) {
            totMoney += arr[i];
        }
        else if ((totMoney + arr[i]) >= 0) {
            totMoney += arr[i];
        }
        else {
            isPushed = true;
        }
        if (totMoney > 0) {
            int currentIndex = i;
            while ((!stack1.empty()) && (totMoney > 0)) {
                int top = stack1.front();
               
                if (totMoney > abs(arr[top])) {
                    stack1.pop();
                    totMoney -= abs(arr[top]);
                    steps += abs(currentIndex-top);
                    currentIndex = top;
                }
                else {
                    break;
                }
            }
            steps += abs(currentIndex - i);
        }
        if (isPushed) {
            stack1.push(i);
        }
        //cout << "MONEY AT INDEX " << i << " IS " << totMoney << " AND STEPS ARE " << steps << endl;
    }
    cout << steps;
}

