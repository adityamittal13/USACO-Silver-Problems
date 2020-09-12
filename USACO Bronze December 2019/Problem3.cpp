#include <fstream>
#include <string>
using namespace std;


ifstream fin("lineup.in");
ofstream fout("lineup.out");

struct constraint{
  int one, two;
};

int main(){
  int n1;
  fin >> n1;

  string m;
  getline(fin, m);


  string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

  constraint constraints[n1];
  for (int i = 0; i < n1; i++){
    string l;
    getline(fin, l);
    string a = "";
    int count = 0;
    for (int j = 0; j < l.length(); j++){
        if (l[j] == ' '){
          break;
        } else {
          a += l[j];
          count++;
        }
    }

    string b = l.substr(count+23, l.length()-count-23);

    //fout << a << " " << b << endl;

    for (int j = 0; j < 8; j++){
      if (a == cows[j]){
        constraints[i].one = j;
      } else if (b == cows[j]){
        constraints[i].two = j;
      }
    }

    //fout << cows[constraints[i].one] << "  " << cows[constraints[i].two] << endl;
  }

  int arr[8] = {0};
  bool allwork;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (i!=j){
        for (int k = 0; k < 8; k++){
          if ((j!=k) && (i!=k)){
            for (int l = 0; l < 8; l++){
              if ((i!=l) && (j!=l) && (k!=l)){
                for (int m = 0; m < 8; m++){
                  if ((i!=m) && (j!=m) && (k!=m) && (l!=m)){
                    for (int n = 0; n < 8; n++){
                      if ((i!=n) && (j!=n) && (k!=n) && (l!=n) && (m!=n)){
                        for (int o = 0; o < 8; o++){
                          if ((i!=o) && (j!=o) && (k!=o) && (l!=o) && (m!=o) && (n!=o)){
                            for (int p = 0; p < 8; p++){
                              if ((i!=p) && (j!=p) && (k!=p) && (l!=p) && (m!=p) && (n!=p) && (o!=p)){
                                arr[0] = i;
                                arr[1] = j;
                                arr[2] = k;
                                arr[3] = l;
                                arr[4] = m;
                                arr[5] = n;
                                arr[6] = o;
                                arr[7] = p;

                                allwork = true;
                                for (int q = 0; q < n1; q++){
                                  int index = -1;
                                  for (int r = 0; r < 8; r++){
                                    if (constraints[q].one == arr[r]){
                                      index = r;
                                      break;
                                    }
                                  }
                                  bool work = false;
                                  if (index == 0){
                                    if (arr[1] == constraints[q].two){
                                      work = true;
                                    }
                                  } else if (index == 7){
                                    if (arr[6] == constraints[q].two){
                                      work = true;
                                    }
                                  } else if ((arr[index-1] == constraints[q].two) || (arr[index+1] == constraints[q].two)){
                                    work = true;
                                  }

                                  if (!work){
                                    allwork = false;
                                    break;
                                  }
                                }

                                if (allwork){
                                  break;
                                }
                              }
                            }
                          }
                          if (allwork){
                            break;
                          }
                        }
                      }

                      if (allwork){
                        break;
                      }
                    }
                  }

                  if (allwork){
                    break;
                  }
                }
              }

              if (allwork){
                break;
              }
            }
          }

          if (allwork){
            break;
          }
        }
      }

      if (allwork){
        break;
      }
    }

    if (allwork){
      break;
    }
  }

  for (int i = 0; i < 8; i++){
    fout << cows[arr[i]] << endl;
  }
}