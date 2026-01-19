#include<bits/stdc++.h>
using namespace std;

struct item {
    int profit;
    int weight;
};

bool compare(item a, item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

void knapsack01(int W) {
    int n; 
    cin >> n; 
    item arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].profit >>  arr[i].weight;
    }
    sort(arr, arr + n, compare);

    int dp[n + 1][W + 1];

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            } else if(arr[i - 1].weight <= w){
                dp[i][w] = max(arr[i - 1].profit + dp[i - 1][w - arr[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][W] << endl;
}


int main(){
    int size; 
    cin >> size;

    knapsack01(size);
    return 0; 
}