#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n; 
    vector<int> stock(n);
    for(int i = 0; i < n; i++){
        cin >> stock[i];
    }
    vector<int> span(n);
    stack<int> s;
    s.push(0);
    span[0] = 1;    
    for(int i = 1; i < n; i++){
        while(!s.empty() && stock[s.top()] <= stock[i]){
            s.pop();
        }
        span[i] = s.empty() ? (i + 1) : (i - s.top());
        s.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << span[i] << " ";
    }
    cout << endl;
    return 0;
}