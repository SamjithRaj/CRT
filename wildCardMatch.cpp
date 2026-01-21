#include<bits/stdc++.h>
using namespace std; 

int wildcardMatching(int i, int j, string &s1, string &s2){
    if(i < 0 && j < 0){
        return 1;
    }
    if(j < 0){
        while(i >= 0 && s1[i] == '*'){
            i--;
        }
        return i < 0 ? true : false;
    }
    if(i < 0){
        return 0;
    }
    if(s1[i] == '*'){
        return wildcardMatching(i-1, j, s1, s2) || wildcardMatching(i, j-1, s1, s2);
    }
    if(s1[i] == s2[j]){
        return wildcardMatching(i-1, j-1, s1, s2);
    }
    if(s1[i] == '?'){
        return wildcardMatching(i-1, j-1, s1, s2);
    }
    return 0;
}

int main(){
    string s1, s2; 
    cin >> s1 >> s2;
    if(wildcardMatching(s1.length() - 1, s2.length() - 1, s1, s2)){
        cout << "Matched" << endl;
    } else {
        cout << "Not Matched" << endl;
    }
    return 0;
}