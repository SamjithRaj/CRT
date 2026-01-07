#include<bits/stdc++.h>
using namespace std;

int minMoves(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return 1 + min(minMoves(n-1), minMoves(n - 2));
}

int main(){
    
    int n;
    cin >> n;
    cout << minMoves(n) << endl;
    return 0;
}