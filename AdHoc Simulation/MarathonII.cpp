/*
Marathon II
===========

Unhappy with the poor health of his cows, Farmer John enrolls them in
an assortment of different physical fitness activities.  His prize cow
Bessie is enrolled in a running class, where she is eventually
expected to run a marathon through the downtown area of the city near
Farmer John's farm!

The marathon course consists of N checkpoints (3 <= N <= 100,000) to
be visited in sequence, where checkpoint 1 is the starting location
and checkpoint N is the finish.  Bessie is supposed to visit all of
these checkpoints one by one, but being the lazy cow she is, she
decides that she will skip up to one checkpoint in order to shorten
her total journey.  She cannot skip checkpoints 1 or N, however, since
that would be too noticeable.

Please help Bessie find the minimum distance that she has to run if
she can skip up to one checkpoint.  

Note that since the course is set in a downtown area with a grid of
streets, the distance between two checkpoints at locations (x1, y1)
and (x2, y2) is given by |x1-x2| + |y1-y2|.  This way of measuring
distance -- by the difference in x plus the difference in y -- is
sometimes known as "Manhattan" distance because it reflects the fact
that in a downtown grid, you can travel parallel to the x or y axes,
but you cannot travel along a direct line "as the crow flies".

PROBLEM NAME: marathon2

INPUT:

The first line gives the value of N.

The next N lines each contain two space-separated integers, x and y,
representing a checkpoint (-1000 <= x <= 1000, -1000 <= y <= 1000).
The checkpoints are given in the order that they must be visited.
Note that the course might cross over itself several times, with
several checkpoints occurring at the same physical location.  When
Bessie skips such a checkpoint, she only skips one instance of the
checkpoint -- she does not skip every checkpoint occurring at the same
location.

SAMPLE INPUT:

4
0 0
8 3
11 -1
10 0

OUTPUT:

Output the minimum distance that Bessie can run by skipping up to one
checkpoint.  Don't forget to end your output with a newline.  In the
sample case shown here, skipping the checkpoint at (8, 3) leads to the
minimum total distance of 14.

SAMPLE OUTPUT:

14
*/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_INT 1000000000;

struct Point {int x, y;};

int main(){
    int n;
    cin >> n;
    
    Point arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    
    int total_distance = 0;
    for (int i = 0; i < n-1; i++){
        total_distance += abs(arr[i].x - arr[i+1].x) + abs(arr[i].y - arr[i+1].y);
    }
    int minimum = MAX_INT;
    for (int i = 1; i < n-1; i++){
        int count = total_distance;
        count -= abs(arr[i-1].x - arr[i].x) + abs(arr[i-1].y - arr[i].y);
        count -= abs(arr[i].x - arr[i+1].x) + abs(arr[i].y - arr[i+1].y);
        count += abs(arr[i-1].x - arr[i+1].x) + abs(arr[i-1].y - arr[i+1].y);
        
        minimum = min(minimum, count);
    }
    
    cout << minimum;
}