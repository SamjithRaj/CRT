#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string s, int left, int right, vector<string>& result) {
    if (left == right) {
        result.push_back(s);
        return;
    }
    
    for (int i = left; i <= right; i++) {
        swap(s[left], s[i]);
        permute(s, left + 1, right, result);
        swap(s[left], s[i]); // backtrack
    }
}

int main() {
    string s = "abc";
    vector<string> result;
    
    permute(s, 0, s.length() - 1, result);
    
    cout << "All permutations of \"" << s << "\":" << endl;
    for (const string& perm : result) {
        cout << perm << endl;
    }
    
    return 0;
}