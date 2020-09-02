#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 4;
    int y = 9;
    int n= 10;
    int arr[10] = {36, 9, 2191, 66, 3, 4, -18, 876, 156, 12};
    int index;
    int r;
    for (int i = x; i < y; i++) {
        index = i;
        for (int j = i+1; j < y; j++) {
            if (arr[i] > arr[j]) {
                index = j;
            }
        }
        r = arr[i];
        arr[i] = arr[index];
        arr[index] = r;
        
    }
    
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}
