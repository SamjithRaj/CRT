#include<bits/stdc++.h>
using namespace std; 

bool nextPermutation(string& s){
    int n = s.length();
    int i = n - 2;
    while(i >= 0 && s[i] >= s[i + 1]){
        i--;
    }
    if(i < 0){
        reverse(s.begin(), s.end());
        return false;
    }
    int j = n - 1;
    while(s[j] <= s[i]){
        j--;
    }
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return true;
}

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do{
        cout << s << " ";
    }while(nextPermutation(s));
    return 0;
}