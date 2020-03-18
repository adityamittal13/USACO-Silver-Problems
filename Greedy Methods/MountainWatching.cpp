/*
Mountain Watching
=================

One day, Bessie was gazing off into the distance at the beautiful 
Wisconsin mountains when she wondered to herself: which is the 
widest one?

She decided to take N (1 <= N <= 10,000) height measurements H_i
(1 <= H_i <= 1,000,000,000) sequentially along the horizon using
her new Acme Long Distance Geoaltimeter. 

A mountain is defined to be a consecutive sequence of H_i values
which increases (or stays the same) and then decreases (or stays     
the same), e.g., 2, 3, 3, 5, 4, 4, 1. It is possible for a mountain
on the edge of her field of vision only to increase or only to      
decrease in height, as well.

The width of a mountain is the number of measurements it encompasses.
Help Bessie identify the widest mountain.

Here's a simple example of a typical horizon:

           *******                   *
          *********                 ***
          **********               *****
          ***********           *********               *
*      *****************       ***********             *** *
**    *******************     *************   * *     *******      *
**********************************************************************
?ddsssuussuussssssddddssddssssuuuuuuuuddddddssududssssuuudduddsssssuds
3211112333677777776543332111112344456765432111212111112343232111111211
aaaaa                     cccccccccccccccccccc eeeeeee    ggggggggg
  bbbbbbbbbbbbbbbbbbbbbbbbbbbb             ddddd ffffffffff  hhhhhhhhh

The mountains are marked 'a', 'b', etc.  Obviously, mountain b is
widest with width 28.

Hint: Sometimes it's easiest to find a mountain's width by knowing
where its highest parts are.

PROBLEM NAME: mount

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: H_i

SAMPLE INPUT:

7
3
2
3
5
4
1
6

INPUT DETAILS:

The height measurements are 3, 2, 3, 5, 4, 1, 6.

OUTPUT FORMAT:

* Line 1: A single line with a single integer that is the width of the
        widest mountain.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

The widest mountain consists of the measurements 2, 3, 5, 4, 1. Other
mountains include 3, 2 and 1, 6
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int maximum = 0;
    for (int i = 0; i < n; i++){
        bool leftvalid = (i-1) >= 0;
        bool rightvalid = (i+1) <= n-1;
        int currleft = i;
        int currright = i;
        
        int count = 1;
        while (true){
            bool either = false;
            
            if (leftvalid && (arr[currleft - 1] <= arr[currleft])){
                count++;
                currleft -= 1;
                either = true;
            }
            
            if (rightvalid && (arr[currright + 1] <= arr[currright])){
                count++;
                currright += 1;
                either = true;
            }
            
            leftvalid = (currleft - 1) >= 0;
            rightvalid = (currright + 1) <= n-1;
            
            if (!either || (!leftvalid && !rightvalid)){
                break;
            }
        }
        maximum = max(count, maximum);
    }
    
    cout << maximum;
}