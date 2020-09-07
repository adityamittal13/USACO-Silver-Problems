#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cout << "Please input the number of operations you wish to do: ";
    cin >> n;

    stack<int> arr;
    for (int i = 0; i < n; i++){
        string l; int r;
        cin >> l;

        if (l == "push"){
            cin >> r;
            arr.push(r);
        } else if (l == "pop"){
            arr.pop();
        }
    }

    while (!arr.empty()){
        cout << arr.top() << " ";
        arr.pop();
    }
}