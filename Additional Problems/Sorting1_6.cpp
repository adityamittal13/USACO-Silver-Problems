#include <iostream>
using namespace std;

int main(){
    int n = 9;
    int val = 15;

    int arr[10] = {-18, 3, 4, 9, 12, 36, 66, 156, 876};

    int mid = arr[9/2];
    int midi = 5;
    int Li = 0;
    int Ri = 9;

    bool isFound = false;
    while (true){
        if (val < mid) {
            Ri = midi;
        } else if (val > mid) {
            Li = midi;
        } else if (val == mid){
            isFound = true;
            break;
        } 

        mid = arr[(Li + Ri)/2];
        midi = (Li + Ri)/2;

        if (Li == Ri || Li == Ri+1 || Li+1 == Ri){
            cout << Li << " " << Ri << " " << midi << endl;
            break;
        }
    }

    if (isFound){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}