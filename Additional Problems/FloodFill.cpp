#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N = 7;
int M = 5;
int arr[7][5] = {{0, 0, 1, 0, 1},
                {0, 0, 1, 0, 0},
                {0, 1, 0, 1, 0},
                {0, 1, 0, 1, 0},
                {1, 0, 0, 1, 0},
                {1, 1, 1, 1, 1},
                {1, 0, 0, 0, 1}};
int arr2[7][5];
int arr_gs[7][5];
int arr_id[7][5];
                    
int floodFill(int x, int y){
    if (x < 0 || x >= N || y < 0 || y >= N){
        return 0;
    }
    
    if (arr[x][y] != 0){
        return 0;
    }
    
    arr[x][y] = 2;
    
    int res = 1;
    
    res += floodFill(x+1, y);
    res += floodFill(x-1, y);
    res += floodFill(x, y+1);
    res += floodFill(x, y-1);
    return res;
}

void h (int x, int y, int gs){
    if (x < 0 || x >= N || y < 0 || y >= N){
        return;
    }
    
    if (arr[x][y] != 2 || arr_gs[x][y] == gs){
        return;
    }
    
    arr_gs[x][y] = gs;
    
    h(x+1, y, gs);
    h(x-1, y, gs);
    h(x, y+1, gs);
    h(x, y-1, gs);
}

void h_id (int x, int y, int gs){
    if (x < 0 || x >= N || y < 0 || y >= N){
        return;
    }
    
    if (arr[x][y] != 2 || arr_id[x][y] == gs){
        return;
    }
    
    arr_id[x][y] = gs;
    
    h_id(x+1, y, gs);
    h_id(x-1, y, gs);
    h_id(x, y+1, gs);
    h_id(x, y-1, gs);

}

/* void a (int x, int y){
    if (x<0 || x >=7 || y<0 || y>=7){
        return;
    }
    if (arr[x][y] != 0 ){
        return;
    }
    
    a(x, y+1);
    a(x, y-1);
    a(x+1, y);
    a(x-1,y);
} */

int returnSum(int x, int y){
    int sumF = 0;
    int id1, id2, id3, id4 = 0;
    
    if (!(x < 1) && (arr_gs[x-1][y] != 1)){
        sumF += arr_gs[x-1][y];
        id1 = arr_id[x-1][y];
    }
    
    if (!(x>(N-1)) && (arr_id[x+1][y] != id1) && (arr_gs[x+1][y] != 1)){
        sumF += arr_gs[x+1][y];
        id2 = arr_id[x+1][y];
    }
    
    if (!(y < 1) && (arr_id[x][y-1] != id1) && (arr_id[x][y-1] != id2) && (arr_gs[x][y-1] != 1)){
        sumF += arr_gs[x][y-1];
        id3 = arr_id[x][y-1];
    }
    if (!(y>(N-1)) && (arr_id[x][y+1] != id1) && (arr_id[x][y+1] != id2) && (arr_id[x][y+1] != id3) && (arr_gs[x][y+1] != 1)){
        sumF += arr_gs[x][y+1];
        id4 = arr_id[x][y+1];
    }
    
    return sumF;
}

void arrayH(){
    arr_id[1][0] = 2;
    arr_id[1][1] = 2;
    arr_id[2][0] = 2;
    arr_id[3][0] = 2;
}

int main(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            arr2[i][j] = arr[i][j];
            arr_gs[i][j] = arr[i][j];
            arr_id[i][j] = arr[i][j];
        }
    }
    
    int id = 1;
    int gs, count, x;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (arr[i][j] == 0){
                gs = floodFill(i, j);
                
                h(i, j, gs);
                
                id++;
                h_id(i, j, id);
            }
        }
    }
    arrayH();
    
    vector<int> sums;
    int count1 = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int sum = 0;
            if (arr_id[i][j] == 1){
                sum = returnSum(i, j);
                sums.push_back(sum);
                
                //cout << sum << " " << i << " " << j << endl;
                
                count1 += 1;
            }
        }
    }
    
    sort(sums.begin(), sums.end());
    
    int max = sums.at(count1-1);
    
    /*for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << arr_gs[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << arr_id[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    
    cout << max;
}