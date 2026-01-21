#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n; 
    cin >> n; 
    int sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += nFib(digit);
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}
