/*
Milking Cows
============

Three farmers rise at 5 am each morning and head for the barn to 
milk three cows. The first farmer begins milking his cow at time 
300 (measured in seconds after 5 am) and ends at time 1000. The 
second farmer begins at time 700 and ends at time 1200. The third 
farmer begins at time 1500 and ends at time 2100. The longest 
continuous time during which at least one farmer was milking a cow 
was 900 seconds (from 300 to 1200). The longest time no milking was 
done, between the beginning and the ending of all milking, was 300 
seconds (1500 minus 1200).

Your job is to write a program that will examine a list of beginning 
and ending times for N (1 <= N <= 5000) farmers milking N cows and 
compute (in seconds):

* The longest time interval at least one cow was milked.

* The longest time interval (after milking starts) during which no 
cows were being milked. 

PROGRAM NAME: milk2

INPUT FORMAT:

* Line 1: The single integer

* Lines 2..N+1: Two non-negative integers less than 1000000, the 
           starting and ending time in seconds after 0500

SAMPLE INPUT:

3
300 1000
700 1200
1500 2100

OUTPUT FORMAT:

A single line with two integers that represent the longest 
continuous time of milking and the longest idle time.

SAMPLE OUTPUT:

900 300
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int s[n];
    int origs[n];
    int e[n];
    int orige[n];
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        
        s[i] = start;
        origs[i] = start;
        e[i] = end;
        orige[i] = end;
    }
    
    sort(s, s+n);
    sort(e, e+n);
    
    int arr[e[n-1]];
    for (int i = 0; i < e[n-1]; i++){
        arr[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = origs[i]; j < orige[i]; j++){
            arr[j] = 1;
            //cout << "origs[i] is " << origs[i] << ", and orige[i] is " << orige[i] << ", and i is: " << i << endl;
        }
    }
    
    for (int i = 0; i < e[n-1]; i++){
       //cout << arr[i] << " " << i << endl;
    }
    
    bool isMilking;
    if (s[0] == 1){
        isMilking = true;
    } else {
        isMilking = false;
    }
    int maxMilk = 0;
    int maxIdle = 0;
    int countMilk = 0;
    int countIdle = 0;
    //cout << "{";
    for (int i = s[0]; i < e[n-1]; i++){
        //cout << arr[i] << ", ";
        
        if (isMilking && arr[i] == 1){
            countMilk++;
            //cout << "counting milk at index i: " << i << ", count milk is " << countMilk << endl;
        } else if (isMilking && arr[i] == 0){
            countMilk++;
            maxMilk = max(countMilk, maxMilk);
            //cout << "changing to idle: count milk is " << countMilk << " at index i" << i << endl;
            countMilk = 0;
            isMilking = false;
        } else if (!isMilking && arr[i] == 0){
            countIdle++;
            //cout << "counting idle at index i: " << i << ", count idle is " << countIdle << endl;
        } else {
            countIdle++;
            maxIdle = max(countIdle, maxIdle);
            //cout << "changing to milk: count idle is " << countIdle << " at index i" << i << endl;
            countIdle = 0;
            isMilking = true;
        }
    }
    maxMilk = max(countMilk, maxMilk);
    maxIdle = max(countIdle, maxIdle);
    //cout << "}" << endl;
    cout << maxMilk << " " << maxIdle;
}