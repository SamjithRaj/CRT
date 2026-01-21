#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n; 
    if(n <= 0) return 0;
    vector<long long> fib(n);
    fib[0] = 0;
    long long sum = 0;
    sum += fib[0];
    if(n > 1) {
        fib[1] = 1;
        sum += fib[1];
    }
    for(int i = 2; i<n; i++){
        fib[i] = fib[i-1] + fib[i-2];
        sum += fib[i];
    }
    cout << "Nth Fibonacci Term: " << fib[n-1] << endl;
    cout << "Sum of " << n << " terms: " << sum << endl;
    return 0;
}