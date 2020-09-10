#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");

int main() {
  int K, N;
  fin >> K >> N;

  int cows[K][N];
  for (int i = 0; i < K; i++){
    for (int j = 0; j < N; j++){
      fin >> cows[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++){
    for (int j = i+1; j < N; j++){
        int cow1 = cows[0][i];
        int cow2 = cows[0][j];

        bool workpair = true;
        for (int k = 1; k < K; k++){
          bool cow1found = false;
          bool cow2found = false;

          for (int l = 0; l < N; l++){
            if (cow1 == cows[k][l]){
              cow1found = true;
              break;
            } else if (cow2 == cows[k][l]){
              cow2found = true;
              break;
            }
          }

          if (cow2found){
            workpair = false;
            break;
          }
        }

        if (workpair){
          count++;
        }
    }
  }

  fout << count;
}