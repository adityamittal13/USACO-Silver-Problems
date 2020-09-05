#include <iostream>
#include <string>
using namespace std;

int main(){
    string val = "program";

    string arr[5] = {"science", "program", "math", "and", "advanced"};

    string mid = arr[2];
    int midi = 2;
    int Li = 0;
    int Ri = 4;

    bool isFound = false;
    while (true){
        if (val > mid) {
            Ri = midi;
        } else if (val < mid) {
            Li = midi;
        } else if (val == mid){
            isFound = true;
            break;
        } 

        mid = arr[(Li + Ri)/2];
        midi = (Li + Ri)/2;

        if (Li == Ri){
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