#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> Weight = {2, 3, 5, 1};
    vector<int> Profit = {30, 40, 60, 50};
    int n = Weight.size();
    int W;
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(Weight[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], Profit[i-1] + dp[i-1][w - Weight[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}