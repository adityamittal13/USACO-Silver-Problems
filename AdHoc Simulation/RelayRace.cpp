/*
Relay Race
==========

The N (1 <= N <= 1,000) cows conveniently numbered 1..N are competing
in a unique relay race during which multiple cows can run simultaneously.

Before time t=0, each cow is positioned at the starting line, waiting
for her turn to run one lap around a circular track whose finish
line is the same as the starting line.

At time t=0, cow 1 starts running around the track and re-crosses
the starting line exactly L_1 seconds later. In general, cow i's
time to run a lap is L_i (1 <= L_i <= 1,000). As soon as she
re-crosses the starting line, she signals M_1 other cows numbered
A_1j to start instantly. Generally, cow i signals M_i cows (0 <=
M_i <= N) named A_ij (1 <= j <= M_i) to start running. Sooner or
later, every cow is signaled at least once. Sometimes M_i might be
0 and no A_ij's exist.

Each of the signaled cows starts running and performs the signaling
procedure when recrossing the starting line. Multiple cows might
signal the same cow, but every cow wants to run only one lap, so
signals after the first one it receives are ignored.

Farmer John wants you to determine the total race time (i.e., how
long it takes for the final cow to complete her lap).

Consider a small race with 5 cows. The table below shows the Cow
ID (i), her time to run a single lap (L_i), the number of signals
cow i will perform when she finishes (M_i), and the (potentially
empty) list of cows to be signaled (A_ij):

            i   L_i  M_i   A_i*
            1    4    2    2 4
            2    3    3    1 3 4
            3    7    1    5
            4    4    2    3 5
            5    1    0

Starting cow 1 at time 0 leads to this timeline of events:

   TIME		Event
     0		Cow 1 starts running
     4		Cow 1 finishes; signals 2 and 4
     4		Cow 2 starts running (time to finish: +3 seconds -> 7)
     4		Cow 4 starts running (time to finish: +4 seconds -> 8)
     7		Cow 2 finishes; signals 1, 3, and 4
     7		Cows 1 and 4 ignore the duplicate signal
     7		Cow 3 starts (time to finish: +7 seconds -> 14)
     8		Cow 4 finishes; signals 3 and 5
     8		Cow 3 ignores the duplicate signal
     8		Cow 5 starts (time to finish: +1 seconds -> 9)
     9		Cow 5 finishes but has no other cows to signal
    14		Cow 3 finishes; signals 5
    14		Cow 5 ignores the duplicate signal
    14		All cows have finished

Thus, the race will last 14 seconds.

PROBLEM NAME: relayrace

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains multiple space-separated integers:
        L_i, M_i and then M_i integers A_ij

SAMPLE INPUT:

5
4 2 2 4
3 3 1 3 4
7 1 5
4 2 3 5
1 0

OUTPUT FORMAT:

* Line 1: A single integer, the time the last cow finishes

SAMPLE OUTPUT:

14
*/

#include <iostream>
#include <vector>
using namespace std;

struct Cow{
    int timerun;
    vector<int> v;
    bool startrunning;
    int timelefttorun;
    bool donerunning;
};

int main(){
    int n;
    cin >> n;
    
    Cow cows[n];
    for (int i = 0; i < n; i++){
        Cow example;
        cin >> example.timerun;
        
        example.timelefttorun = example.timerun;
        example.donerunning = false;
        example.startrunning = false;
        int f;
        cin >> f;
        
        for (int j = 0; j < f; j++){
            int q;
            cin >> q;
            
            example.v.push_back(q);
        }
        
        cows[i] = example;
        
        /*cout << example.timerun << " [";
        for (vector<int>::iterator it = example.v.begin(); it != example.v.end(); it++){
            cout << (*it) << " ";
        }
        cout << "] " << example.startrunning << " " << example.timelefttorun << " " << example.donerunning << endl;*/
    }
    
    long long currtime = cows[0].timerun;
    cows[0].donerunning = true;
    
    for (vector<int>::iterator it = cows[0].v.begin(); it != cows[0].v.end() ; it++){
        cows[(*it) - 1].startrunning = true;
        //cout << (*it)-1 << endl;
    }
    
    while (true){
        currtime++; 
        
        bool allcomplete = true;
        for (int i = 0; i < n; i++){
            if (!cows[i].donerunning){
                allcomplete = false;
                break;
            }
        }
        
        if (allcomplete)
            break;
        
        for (int i = 0; i < n; i++){
            //cout << "Reached " << endl;
            if (cows[i].startrunning){
                cows[i].timelefttorun--;
                if (cows[i].timelefttorun == 0) {
                    cows[i].startrunning = false;
                    cows[i].donerunning = true;
                    for (vector<int>::iterator it = cows[i].v.begin(); it != cows[i].v.end(); it++){
                        if (!cows[(*it) - 1].donerunning)
                            cows[(*it) - 1].startrunning = true;
                    }
                }
            } 
        }
    }
    
    if (n ==1) cout << currtime-1;
    else cout << currtime;
}