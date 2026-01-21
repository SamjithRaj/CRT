#include<bits/stdc++.h>
using namespace std;

void longestPalindromicSubsequence(string s) {
    int n = s.length();
    if (n == 0) return;
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (s[i] == s[j] && cl == 2)
                dp[i][j] = 2;
            else if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    string lps = "";
    int len = dp[0][n - 1];
    lps.resize(len);
    int i = 0, j = n - 1;
    int start = 0, end = len - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            lps[start++] = s[i];
            lps[end--] = s[j];
            i++;
            j--;
        } else if (dp[i][j - 1] > dp[i + 1][j]) {
            j--;
        } else {
            i++;
        }
    }
    cout << lps << endl;
}

int main(){
    string s;
    cin >> s;
    longestPalindromicSubsequence(s);
    return 0;
}
