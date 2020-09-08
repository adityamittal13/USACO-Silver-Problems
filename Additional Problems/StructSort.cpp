#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

bool comp (Point a, Point b) {
    bool val = (a.x % 10) < (b.x % 10);
    bool equals = (a.x % 10) == (b.x % 10);
    bool val2 = ((a.y/10)%10) < ((b.x/10)%10);

    return val || (equals && val2);
}
int main(){
    Point p1 = {18, 82};
    Point p2 = {5, 77};
    Point p3 = {43, 42};
    Point p4 = {73, 129};
    Point p5 = {0, 60};

    Point arr[5] = {p1, p2, p3, p4, p5};

    sort(arr, arr+5, comp);

    for (int i = 0; i < 5; i++){
        cout << arr[i].x << " " << arr[i].y << endl;
    }
}