#include<bits/stdc++.h>
using namespace std;

int editDistance(int i, int j, string& s1, string& s2){
    if (i == 0) return j;
    if (j == 0) return i;

    if (s1[i-1] == s2[j-1]) {
        return editDistance(i-1, j-1, s1, s2);
    }

    int insert = editDistance(i, j-1, s1, s2);
    int del = editDistance(i-1, j, s1, s2);
    int replace = editDistance(i-1, j-1, s1, s2);

    return 1 + min({insert, del, replace});
}

int main(){
    string s1, s2; 
    cin >> s1 >> s2;
    cout << editDistance(s1.length(), s2.length(), s1, s2) << endl;
    return 0;
}