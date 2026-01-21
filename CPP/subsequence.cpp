#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string s, string curr, int index) {
    if (index == s.length()) {
        cout << curr << endl;
        return;
    }
    printSubsequence(s, curr + s[index], index + 1);
    printSubsequence(s, curr, index + 1);
}

int main(){
    string s1; 
    cin >> s1;
    printSubsequence(s1, "", 0);
    return 0;

}