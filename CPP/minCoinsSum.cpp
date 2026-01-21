#include<bits/stdc++.h>
using namespace std;

int minSum(vector<int>& coins, int n, int sum, vector<int>& memo) {
    if (sum == 0) {
        return 0;
    }
    if (sum < 0) {
        return INT_MAX;
    }
    if (memo[sum] != -1) return memo[sum];

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int sub_res = minSum(coins, n, sum - coins[i], memo);
        if (sub_res != INT_MAX) {
            res = min(res, sub_res + 1);
        }
    }
    return memo[sum] = res;
}

int count(vector<int> &coins, int sum) {
    vector<int> memo(sum + 1, -1);
    return minSum(coins, coins.size(), sum, memo);
}

int main() {
    vector<int> coins = {1, 3, 4};
    int sum = 6;
    int result = count(coins, sum);
    if (result == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << result << endl;
    }
    return 0;
}