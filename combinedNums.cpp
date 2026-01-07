#include<bits/stdc++.h>
using namespace std;


int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

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

int nFib(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    
    int a = 0, b = 1;
    for(int i = 3; i <= n; i++){
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}


void factorialSumOfDigits(int n) {
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int temp = n;
        if (temp == 0) sum += factorial(0);
        while(temp > 0){
            sum += factorial(temp % 10);
            temp /= 10;
        }
    }
     cout << "Sum of factorials: " << sum << endl;
}

void primeSumOfDigits(int n) {
    int sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += nPrime(digit);
        n /= 10;
    }
    cout << "Sum of N-th Primes: " << sum << endl;
}

void fibSumOfDigits(int n) {
    int sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += nFib(digit);
        n /= 10;
    }
    cout << "Sum of N-th Fibonacci terms: " << sum << endl;
}

int main(){
    int n; 
    cin >> n; 
    for(int i = 0; i<n; i++){
        int x; 
        cin >> x; 
        factorialSumOfDigits(x);
        primeSumOfDigits(x);
        fibSumOfDigits(x);
    }
        return 0;
}