#include <iostream>
#include <string>
using namespace std;

int main()
{
    string arr[5] = {"advanced" , "math", "and", "science", "program"};
    int index;
    string r;
    for (int i = 0; i < 5; i++) {
        index = i;
        for (int j = i+1; j < 5; j++) {
            if (arr[i] < arr[j]) {
                index = j;
            }
        }
        r = arr[i];
        arr[i] = arr[index];
        arr[index] = r;
        
    }
    
    for (int k = 0; k < 5; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}
