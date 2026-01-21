#include<bits/stdc++.h>
using namespace std; 

int longestIncreasingSubsequence(vector<int> &ls){
    int n = ls.size();
    if(n == 0) return 0;
    vector<int> dp(n, 1);
    vector<long long> count(n, 1);
    int maxLength = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(ls[i] > ls[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if(dp[j] + 1 == dp[i]){
                    count[i] += count[j];
                }
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    long long numberOfLIS = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxLength){
            numberOfLIS += count[i];
        }
    }
    cout << numberOfLIS << endl;
    return maxLength;

}

int main(){
    int n; 
    cin >> n; 
    vector<int> ls(n);
    for(int i = 0; i<n; i++){
        cin >> ls[i];
    }
    cout << longestIncreasingSubsequence(ls) << endl;
    return 0;
}