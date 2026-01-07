#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    if(n <= 1) return 0;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int getNthPrime(int k){
    if(k == 0) return 0;
    int count = 0;
    for(int i = 2; ; i++){
        if(isPrime(i)){
            count++;
            if(count == k) return i;
        }
    }
}

int main(){
    int n; 
    cin >> n; 
    int sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += getNthPrime(digit);
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}