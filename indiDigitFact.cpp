#include<bits/stdc++.h>
using namespace std; 

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main(){
    int n; 
    cin >> n; 
    vector<int> digits;
    int cnt = log10(n) + 1;
    for(int i = 0; i<cnt; i++){
        digits.push_back(factorial(n % 10));
        n /= 10;
    }

    int sum = 0; 
    for(int i = 0; i<digits.size(); i++){
        sum += digits[i];
    }
    cout << sum << endl; 
}