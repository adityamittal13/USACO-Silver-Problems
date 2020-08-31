#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of operations you wish to do: ";
    cin >> n;

    queue<int> arr;
    for (int i = 0; i < n; i++){
        string l; int r;
        cin >> l;

        if (l == "add"){
            cin >> r;
            arr.push(r);
        } else if (l == "get"){
            arr.pop();
        }
    }

    while (!arr.empty()){
        cout << arr.front() << " ";
        arr.pop();
    }

    int a[7] = {1, 3, 3, 3, 7, 8, 10};
    vector<int> v(a,a+7);

    cout << v[3] << endl;
    cout << lower_bound(a,a+7,3)-a << endl;
    cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << endl;
}