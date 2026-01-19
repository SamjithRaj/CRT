#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    if(n <= 1) return 0;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int nPrime(int n){
    if(n == 0) return 0;
    int count = 0;
    for(int i = 2; ; i++){
        if(isPrime(i)){
            count++;
            if(count == n) return i;
        }
    }
}

int main(){
    int n; 
    cin >> n; 
    int sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += nPrime(digit);
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}