/*
Mirror Field
============

Farmer John has left some old mirrors sitting outside his house, and his
cows, feeling mischievous as always, have stolen them!  

The cows have set up the mirrors in a rectangular field measuring N by M
squares (1 <= N, M <= 1,000).  In each square, they have placed a double
sided mirror between two of its opposite corners.  These two possible
configurations are represented by the '/' character (a mirror connecting
the lower-left corner to the upper-right corner) and the '\' character (a
mirror connecting the upper-left corner to the lower-right corner).

One evening, Bessie the cow brings a laser pointer out to the mirror field.
Standing outside the field, she shines the beam of light either
horizontally or vertically along either a row or column of the field,
causing it to bounce on mirrors. Since the mirrors are all diagonally
oriented, a horizontal beam of light that reflects off a mirror will end 
up traveling vertically, and vice versa. Bessie wonders what is the maximum
number of bounces on mirrors on which her beam of light can be reflected
at the same time. Given the layout of the mirror field, please help Bessie
compute this number.

PROBLEM NAME: mirror

INPUT FORMAT:

* Line 1: The integers N and M, separated by a space.

* Lines 2..1+N: Each line will contain M '/' or '\' characters,
        describing a row of the mirror field.

SAMPLE INPUT:

3 3
/\\
\\\
/\/

OUTPUT FORMAT:

* Line 1: A single integer indicating the maximum number of times a
        horizontal or vertical beam originating outside the mirror
        field could be reflected. Please output -1 if it could be
        reflected indefinitely.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

Bessie can shine the beam downwards above the middle column of her
field to have it reflected 3 times.
*/

//Only works for square arrays

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    char arr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    int maximum = 0;
    bool indefinite = false;
    for (int i = 0; i < m; i++){
        if (indefinite)
            break;
        
        int count = 1;
        string direction = "down";
        int currx = i;
        int curry = 0;
        while (count <= m*n){
            if (arr[currx][curry] == '/'){
                if (direction == "down"){
                    currx--;
                    direction = "right";
                } else if (direction == "up"){
                    currx++;
                    direction = "left";
                } else if (direction == "right"){
                    curry++;
                    direction = "down";
                } else if (direction == "left"){
                    curry--;
                    direction = "up";
                }
            } else if (arr[currx][curry] == '\\'){
                if (direction == "down"){
                    currx++;
                    direction = "left";
                } else if (direction == "up"){
                    currx--;
                    direction = "right";
                } else if (direction == "right"){
                    curry--;
                    direction = "up";
                } else if (direction == "left"){
                    curry++;
                    direction = "down";
                }
            }
            
            if ((currx >= 0) && (currx < m) && (curry >= 0) && (curry < n)){
                count++;
            } else {
                break;
            }
        }
        //cout << i << " " << count << endl;
        if (count > m*n){
            indefinite = true;
            break;
        } else {
            maximum = max(maximum, count);
        }
    }
    
    for (int i = 0; i < m; i++){
        if (indefinite)
            break;
        
        int count = 1;
        string direction = "up";
        int currx = i;
        int curry = n-1;
        while (count <= m*n){
            if (arr[currx][curry] == '/'){
                if (direction == "down"){
                    currx--;
                    direction = "right";
                } else if (direction == "up"){
                    currx++;
                    direction = "left";
                } else if (direction == "right"){
                    curry++;
                    direction = "down";
                } else if (direction == "left"){
                    curry--;
                    direction = "up";
                }
            } else if (arr[currx][curry] == '\\'){
                if (direction == "down"){
                    currx++;
                    direction = "left";
                } else if (direction == "up"){
                    currx--;
                    direction = "right";
                } else if (direction == "right"){
                    curry--;
                    direction = "up";
                } else if (direction == "left"){
                    curry++;
                    direction = "down";
                }
            }
            
            if ((currx >= 0) && (currx < m) && (curry >= 0) && (curry < n)){
                count++;
            } else {
                break;
            }
        }
        //cout << i << " " << count << endl;
        if (count > m*n){
            indefinite = true;
            break;
        } else {
            maximum = max(maximum, count);
        }
    }
    
    for (int i = 0; i < n; i++){
        if (indefinite)
            break;
        
        int count = 1;
        string direction = "left";
        int currx = 0;
        int curry = i;
        while (count <= m*n){
            if (arr[currx][curry] == '/'){
                if (direction == "down"){
                    currx--;
                    direction = "right";
                } else if (direction == "up"){
                    currx++;
                    direction = "left";
                } else if (direction == "right"){
                    curry++;
                    direction = "down";
                } else if (direction == "left"){
                    curry--;
                    direction = "up";
                }
            } else if (arr[currx][curry] == '\\'){
                if (direction == "down"){
                    currx++;
                    direction = "left";
                } else if (direction == "up"){
                    currx--;
                    direction = "right";
                } else if (direction == "right"){
                    curry--;
                    direction = "up";
                } else if (direction == "left"){
                    curry++;
                    direction = "down";
                }
            }
            
            if ((currx >= 0) && (currx < m) && (curry >= 0) && (curry < n)){
                count++;
            } else {
                break;
            }
        }
        //cout << i << " " << count << endl;
        if (count > m*n){
            indefinite = true;
            break;
        } else {
            maximum = max(maximum, count);
        }
    }
    
    for (int i = 0; i < n; i++){
        if (indefinite)
            break;
        
        int count = 1;
        string direction = "right";
        int currx = m-1;
        int curry = i;
        while (count <= m*n){
            if (arr[currx][curry] == '/'){
                if (direction == "down"){
                    currx--;
                    direction = "right";
                } else if (direction == "up"){
                    currx++;
                    direction = "left";
                } else if (direction == "right"){
                    curry++;
                    direction = "down";
                } else if (direction == "left"){
                    curry--;
                    direction = "up";
                }
            } else if (arr[currx][curry] == '\\'){
                if (direction == "down"){
                    currx++;
                    direction = "left";
                } else if (direction == "up"){
                    currx--;
                    direction = "right";
                } else if (direction == "right"){
                    curry--;
                    direction = "up";
                } else if (direction == "left"){
                    curry++;
                    direction = "down";
                }
            }
            
            if ((currx >= 0) && (currx < m) && (curry >= 0) && (curry < n)){
                count++;
            } else {
                break;
            }
        }
        //cout << i << " " << count << endl;
        if (count > m*n){
            indefinite = true;
            break;
        } else {
            maximum = max(maximum, count);
        }
    }
    
    if (indefinite) {
        cout << -1;
    } else {
        cout << maximum;
    }
}