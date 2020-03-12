/*
Long Distance Racing
====================

Bessie is training for her next race by running on a path that
includes hills so that she will be prepared for any terrain. She
has planned a straight path and wants to run as far as she can --
but she must be back to the farm within M seconds (1 <= M <=
10,000,000).

The entire path she has chosen is T units (1 <= T <= 100,000) in
length and consists of equal-length portions that are uphill, flat,
or downhill. The input data describes path segment i with a single
character S_i that is u, f, or d, indicating respectively uphill,
flat, or downhill.

Bessie takes U seconds (1 <= U <= 100) to run one unit of uphill
path, F (1 <= F <= 100) seconds for a unit of flat path, and D (1
<= D <= 100) seconds for a unit of downhill path.  Note that, when
returning home, uphill paths become downhill paths and downhill
paths become uphill paths.

Find the farthest distance Bessie can get from the farm and still
make it back in time.

PROBLEM NAME: racing

INPUT FORMAT:

* Line 1: Five space-separated integers: M, T, U, F, and D

* Lines 2..T+1: Line i+1 describes path segment i with a single
        letter: S_i

SAMPLE INPUT:
13 5 3 2 1
u
f
u
d
f

INPUT DETAILS:

Bessie has 13 seconds to get home (short workout!), and the total
path she has planned is 5 units long. She can run an uphill unit
in 3 seconds, a flat unit in 2 seconds, and a downhill unit in 1
seconds. The path looks like this:

 _/\_
/

OUTPUT FORMAT:

* Line 1: A single integer that is the farthest distance (number of
        units) that Bessie can get from the farm and make it back in
        time.

SAMPLE OUTPUT:
3

OUTPUT DETAILS:
She can run three units and back in 3 + 2 + 3 + 1 + 2 + 1 = 12
seconds, just a second less than her limit. If she tried to go
farther she would not make it.
*/

#include <iostream>
using namespace std;

int main(){
    int timeleft, units, uphill, flat, downhill;
    cin >> timeleft >> units >> uphill >> flat >> downhill;
    
    char val[units];
    for (int i = 0; i < units; i++)
        cin >> val[i];
    
    
    int remaining = timeleft;
    int unitsleft = 0;
    while ((remaining >= 0) || (unitsleft == units)){
        if ((val[unitsleft] == 'u') || (val[unitsleft] == 'd'))
            remaining -= uphill + downhill;
        else if (val[unitsleft] == 'f')
            remaining -= flat + flat;
        unitsleft++;
    }
    
    if (remaining < 0){
        cout << unitsleft - 1;
    } else {
        cout << unitsleft;
    }
}