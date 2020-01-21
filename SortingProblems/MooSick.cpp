/*
Moo Sick
========

Everyone knows that cows love to listen to all forms of music.  Almost all
forms, that is -- the great cow composer Wolfgang Amadeus Moozart
once discovered that a specific chord tends to make cows rather ill.  This
chord, known as the ruminant seventh chord, is therefore typically avoided
in all cow musical compositions.

Farmer John, not knowing the finer points of cow musical history, decides
to play his favorite song over the loudspeakers in the barn.  Your task is
to identify all the ruminant seventh chords in this song, to estimate how
sick it will make the cows.

The song played by FJ is a series of N (1 <= N <= 20,000) notes, each an
integer in the range 1..88.  A ruminant seventh chord is specified by a
sequence of C (1 <= C <= 10) distinct notes, also integers in the range
1..88.  However, even if these notes are transposed (increased or decreased
by a common amount), or re-ordered, the chord remains a ruminant seventh
chord!  For example, if "4 6 7" is a ruminant seventh chord, then "3 5 6"
(transposed by -1), "6 8 9" (transposed by +2), "6 4 7" (re-ordered), and
"5 3 6" (transposed and re-ordered) are also ruminant seventh chords.

A ruminant seventh chord is a sequence of C consecutive notes satisfying
the above criteria. It is therefore uniquely determined by its starting
location in the song. Please determine the indices of the starting
locations of all of the ruminant seventh chords.

PROBLEM NAME: moosick

INPUT FORMAT:

* Line 1: A single integer: N.

* Lines 2..1+N: The N notes in FJ's song, one note per line.

* Line 2+N: A single integer: C.

* Lines 3+N..2+N+C: The C notes in an example of a ruminant seventh
        chord.  All transpositions and/or re-orderings of these notes
        are also ruminant seventh chords.

SAMPLE INPUT:

6
1
8
5
7
9
10
3
4
6
7

INPUT DETAILS:

FJ's song is 1,8,5,7,9,10.  A ruminant seventh chord is some
transposition/re-ordering of 4,6,7.

OUTPUT FORMAT:

* Line 1: A count, K, of the number of ruminant seventh chords that
        appear in FJ's song.  Observe that different instances of
        ruminant seventh chords can overlap each-other.

* Lines 2..1+K: Each line specifies the starting index of a ruminant
        seventh chord (index 1 is the first note in FJ's song, index N
        is the last).  Indices should be listed in increasing sorted
        order.

SAMPLE OUTPUT:

2
2
4

OUTPUT DETAILS:

Two ruminant seventh chords appear in FJ's song (and these occurrences
actually overlap by one note).  The first is 8,5,7 (transposed by +1 and
reordered) starting at index 2, and the second is 7,9,10 (transposed by +3)
starting at index 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int notes[num];
    for (int i = 0; i< num; i++){
        int l;
        cin >> l;
        
        notes[i] = l;
    }
    
    int n;
    cin >> n;
    
    int rum[n];
    for (int i = 0; i < n; i++){
        int l1;
        cin >> l1;
        
        rum[i] = l1;
    }
    
    sort(rum, rum + n);

    int counts = 0;
    vector<int> indices;
    int newnotes[n];
    for (int i = 0; i < num-n+1; i++){
        newnotes[n] = {0};
        for (int j = 0; j < n; j++){
            newnotes[j] = notes[i+j];
        }
        
        /*cout << "at i = " << i << "{";
        
        for (int j = 0; j < n; j++){
            cout << newnotes[j] << ", ";
        }
        
        cout << "}" << endl;*/
        sort(newnotes, newnotes + n);
        
        int change = newnotes[0] - rum[0];
        bool works = true;
        for (int j = 1; j < n; j++){
            if (rum[j] + change != newnotes[j]){
                works = false;
                break;
            }
        }
        
        if (works){
            counts++;
            indices.push_back(i+1);
        }
    }
    
    cout << counts << endl;
    for (vector<int>::iterator it = indices.begin(); it != indices.end(); it++){
        cout << (*it) << endl;
    }
}