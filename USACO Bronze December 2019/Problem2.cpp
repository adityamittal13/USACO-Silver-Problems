#include <fstream>
#include <string>
using namespace std;

ifstream fin("whereami.in");
ofstream fout("whereami.out");

int main(){
  int n; string val;
  fin >> n;
  fin >> val;
  
  int max = 0;
  for (int i = 0; i < n; i++){
    int counter = 1;
    while (true){
      string s = val.substr(i, counter);

      bool nosubs = true;
      for (int j = 0; j < (n-counter+1); j++){
        if (i != j){
          string l = val.substr(j, counter);
          if (s == l){
            nosubs = false;
            break;
          }
        }
      }

      if (!nosubs){
        counter++;
      } else {
        break;
      }
    }

    if (counter > max){
      max = counter;
    }
  }

  fout << max;
}