/*
Serious Cow Tag
===============

Farmer John's N (1 <= N <= 1000) cows (conveniently numbered 1..N)
are going to play a game of Serious Cow Tag. In Serious Cow Tag,
each cow chooses a grid point in the pasture (-7500 <= X <= 7500,
-7500 <= Y <= 7500) such that the distances between all pairs of
cows are unique.

The cows play in turn, starting with cow #1 and continuing with
cows #2, #3, and so on (as long as the cow is still in the game).
When it is a cow's turn to play, she finds the nearest cow still
playing, ambles over to that cow to tag her, and then returns to
her original location. As soon as a cow is tagged, she is out of
the game.

The game ends when only one cow remains, and she is declared the
winner.

Farmer John is taking bets with neighboring farmers as to which cow
will win, so he would like to know the winner in advance. Write a
program that will read a description of the cows' positions and
determine the winner.

PROBLEM NAME: cowtag

INPUT FORMAT:

* Line 1: A single integer N, the number of cows

* Lines 2..N+1: Line i+1 contains two space-separated integers that
        describe the location of cow i.

SAMPLE INPUT:

3
0 0
0 3
4 3

INPUT DETAILS:

Three cows at (0, 0), (0, 3) and (4, 3).

OUTPUT FORMAT:

* Line 1: The number of the winning cow.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

Cow 1 goes first and tags the nearest cow, cow 2. Cow 2 is eliminated
so she does not get a turn. Cow 3 then tags the only remaining cow,
cow 1.  She is the last cow left, so she wins.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

struct Point{
    int x, y; bool alive;
};

struct Dist{
    float dist; int index;
};


bool comp(Dist a, Dist b){
    return a.dist < b.dist;
}

int main(){
    int n;
    cin >> n;
    
    Point arr[n];
    for (int i = 0; i < n; i++){
        int l, m;
        cin >> l >> m;
        
        arr[i] = {l, m, true};
    }
    
    for (int i = 0; i < n; i++){
        if (arr[i].alive) { 
            Dist dist[n-1];
            bool isSame = false;
            
            for (int j = 0; j < n; j++) {
                if (i == j){
                    isSame = true;
                } else {
                    float val = sqrt(pow(arr[j].x-arr[i].x, 2)+pow(arr[j].y-arr[i].y, 2));
                    if (isSame){
                        dist[j-1].dist = val;
                        dist[j-1].index = j;
                    } else {
                        dist[j].dist = val;
                        dist[j].index = j;
                    }
                }
            }
            
            sort(dist, dist+n-1, comp);
            
            //cout << "for i = " << i << " dist equals: [";
            for (int j = 0; j < n-1; j++){
                //cout << "(" << dist[j].dist << ", " << dist[j].index << ") , ";
            }
            //cout << "]" << endl;
            
            arr[dist[0].index].alive = false;
            //cout << dist[0].index << " is the one being changed to false" << endl;
            arr[dist[0].index].x = -10000000;
            arr[dist[0].index].y = -10000000;
        }
        
        //cout << "for i = " << i << " arr equals: [";
        for (int j = 0; j < n; j++){
            //cout << "(" << arr[j].x << ", " << arr[j].y << " " << to_string(arr[j].alive) <<  ") , ";
        }
        //cout << "]" << endl;
        
    }
    
    for (int i = 0; i < n; i++){
        if (arr[i].alive == true){
            cout << i+1;
            break;
        }
    }
    
}
