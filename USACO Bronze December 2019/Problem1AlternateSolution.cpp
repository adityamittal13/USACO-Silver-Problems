#include <fstream>
#include <iostream>
using namespace std;
struct Point {
  int cow1, cow2;
};
ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");

int main() {
  int practices, cows;
  fin >> practices >> cows;

  int practice[practices][cows];

  for (int i = 0; i < practices; i++) {
    for (int j = 0; j < cows; j++) {
      fin >> practice[i][j];
    }
  }

  int count = 0;
  int counter = 0;
  Point arr[10000];
  for (int l = 0; l < practices; l++) {
    for (int i = 0; i < cows; i++) {
      for (int j = i+1; j < cows; j++) {
        arr[counter].cow1 = practice[l][i];
        arr[counter].cow2 = practice[l][j];
        counter++;
      }
    }
  }

  Point arr1[counter];

  for (int i = 0; i < counter+1; i++) {
    arr1[i] = arr[i];
    //cout << arr[i].cow1 << " " << arr[i].cow2 << endl;
  }
  //cout << endl;
  for (int i = 0; i < counter; i++) {
    int count2 = 0;
    for (int j = i+1; j < counter; j++) {
      if ((arr1[j].cow1 == arr1[i].cow1) && (arr1[j].cow2 == arr1[i].cow2)) {
        count2++;
        //cout << arr1[j].cow1 << " " << arr1[j].cow2 << " " << count2 << endl;
      }
    }
    if (count2 == (practices-1)) {
      count++;
    }
  }
  fout << count;
}
