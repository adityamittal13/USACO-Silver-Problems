#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(long long int count1){
    for (int i = 2; i < (int) sqrt(count1)+1; i++){
        if (fmod(count1, i) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long long int sum =0;
    for (long long int i = 2; i < 2000001; i++){
        if (isPrime(i)){
            sum += i;
        }
    }

    cout << sum;
}