/*
Exploration
===========

Bessie is traveling on a road teeming with interesting landmarks.
The road is labeled just like a number line, and Bessie starts at
the "origin" (x = 0). A total of N (1 <= N <= 50,000) landmarks are
located at points x_1, x_2, ..., x_N  (-100,000 <= x_i <= 100,000).
Bessie wants to visit as many landmarks as possible before sundown,
which occurs in T (1 <= T <= 1,000,000,000) minutes. She travels 1
distance unit in 1 minute.

Bessie will visit the landmarks in a particular order. Since the
landmarks closer to the origin are more important to Farmer John,
she always heads for the unvisited landmark closest to the origin.
No two landmarks will be the same distance away from the origin.

Help Bessie determine the maximum number of landmarks she can visit
before the day ends.

PROBLEM NAME: explore

INPUT FORMAT:

* Line 1: Two space-separated integers: T and N

* Lines 2..N+1: Line i+1 contains a single integer that is the
        location of the ith landmark: x_i

SAMPLE INPUT:

25 5
10
-3
8
-7
1

INPUT DETAILS:

Bessie has 25 minutes before sundown, and there are 5 landmarks
located at positions 10, -3, 8, -7, and 1.

OUTPUT FORMAT:

* Line 1: The maximum number of landmarks Bessie can visit.

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

Bessie sequentially visits the landmarks at locations 1, -3, -7,
and 8, after which she has traveled a total of 24 minutes.  She
cannot visit the next intended landmark at position 10, since this
would extend her total travel time to 26 minutes.
*/

#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {
    return abs(a)<abs(b);
}
int main() {
    int time1, landmarks;
    cin >> time1 >> landmarks;
   
    int landmark[landmarks];
    for (int i = 0; i < landmarks; i++) {
        int placeholder;
        cin >> placeholder;
        landmark[i] = placeholder;
    }
   
    sort(landmark, landmark+landmarks, comp);
   
    int time2 = 0;
    int count = 0;
    for (int i = 0; i < landmarks; i++) {
        if (i == 0) {
            time2 += abs(landmark[i]);
            //cout << landmark[i] << " " << landmark[i-1] << " " << time2 << endl;
        }
        else {
            time2 += abs(landmark[i] - landmark[i-1]);
            //cout << landmark[i] << " " << landmark[i-1] << " " << time2 << endl;
        }
        if (time2 > time1) {
            break;
        }
        else {
            count++;
            //cout << count << endl;
        }
    }
    cout << count;
}


/*

Approach 2: with vectors

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int dist1, origVal;
};

bool comp(Point a, Point b){
    return a.dist1>b.dist1;
}

int main(){
    int dist, num;
    cin >> dist >> num;
    
    int arr[num];
    for (int i = 0; i < num; i++){
        int l;
        cin >> l;
        
        arr[i] = l;
    }
    
    sort(arr, arr+num);
    
    int start = 0;
    int timeVal = 0;
    int landmarks = 0;
    vector<int> noUse;
    for (int i = 0; i < num; i++){
        if (timeVal < dist){
            vector<Point> distances;
            for (int j = 0; j < num; j++){
                bool notThere = true;
                for (vector<int>::iterator it = noUse.begin(); it != noUse.end(); it++){
                    if (j == (*it)){
                        notThere = false;
                        break;
                    }
                }
                if (notThere)
                    distances.push_back({abs(arr[j]), j});
            }
            int minimum = 1000000;
            int origVal = -1;
            cout << "{";
            for (vector<Point>::iterator it = distances.begin(); it!=distances.end(); it++){
                cout << (*it).dist1 << ", ";
                if ((*it).dist1<minimum){
                    minimum = (*it).dist1;
                    origVal = (*it).origVal;
                }
            }
            cout << "}" << endl;
            timeVal += abs(minimum-start);
            start = arr[origVal];
            cout << "timeval is:  " << timeVal << endl;
            noUse.push_back(origVal);
            landmarks++;
            cout << start << endl;
        } else
            break;
    }
    
    cout << landmarks;
}

#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return abs(a)>abs(b);
}
int main(){
    int dist, num;
    cin >> dist >> num;
    
    int arr[num];
    for (int i = 0; i < num; i++){
        int l;
        cin >> l;
        
        arr[i] = l;
    }
    
    sort(arr, arr+num, comp);
    
    
    
    int n = 0;
    int timeVal = 0;
    while (timeVal <= dist){
        timeVal += abs(arr[n]);
        n++;
    }
    
    cout << n;
}*/