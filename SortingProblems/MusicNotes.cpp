/*
Music Notes
===========

FJ is going to teach his cows how to play a song. The song consists
of N (1 <= N <= 50,000) notes, and the i-th note lasts for B_i (1
<= B_i <= 10,000) beats (thus no song is longer than 500,000,000
beats). The cows will begin playing the song at time 0; thus, they
will play note 1 from time 0 through just before time B_1, note 2
from time B_1 through just before time B_1 + B_2, etc.

However, recently the cows have lost interest in the song, as they
feel that it is too long and boring. Thus, to make sure his cows
are paying attention, he asks them Q (1 <= Q <= 50,000) questions
of the form, "In the interval from time T through just before time
T+1, which note should you be playing?" The cows need your help to
answer these questions which are supplied as T_i (0 <= T_i <=
end_of_song).

Consider this song with three notes of durations 2, 1, and 3 beats:

Beat:   0    1    2    3    4    5    6    ...
        |----|----|----|----|----|----|--- ...
        1111111111     :              :
                  22222:              :
                       333333333333333:

Here is a set of five queries along with the resulting answer:

   Query    Note
     2        2
     3        3
     4        3
     0        1
     1        1

PROBLEM NAME: mnotes

INPUT FORMAT:

* Line 1: Two space-separated integers: N and Q
* Lines 2..N+1: Line i+1 contains the single integer: B_i
* Lines N+2..N+Q+1: Line N+i+1 contains a single integer: T_i

SAMPLE INPUT:

3 5
2
1
3
2
3
4
0
1

OUTPUT FORMAT:

* Lines 1..Q: For each query, print a single integer that is the index
        of the note that the cows should be playing.

SAMPLE OUTPUT:

2
3
3
1
1
*/

#include <iostream>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    int notes[n];
    notes[0] = 0;
    
    for (int i = 1; i < n; i++){
        int l;
        cin >> l;
        
        notes[i] = l + notes[i-1];
    }
    
    int f;
    cin >> f;
    
    for (int i = 0; i < q; i++){
        int query;
        cin >> query;
        
        bool found = false;
        for (int j = 1; j < n; j++){
            if (notes[j] > query) {
                found = true;
                cout << j << endl;
                break;
            }
        }
        
        if (!found)
            cout << n << endl;
    }
}
