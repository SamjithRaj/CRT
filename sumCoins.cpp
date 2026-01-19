#include <bits/stdc++.h>
using namespace std;

int countSum(vector<int>& ele, int n, int sum) {
    if (sum == 0){
        return 1;
    }
    if (sum < 0 || n == 0){
        return 0;
    }
    return countSum(ele, n, sum - ele[n - 1]) + 
            countSum(ele, n - 1, sum);
}

int count(vector<int> &ele, int sum) {
    return countSum(ele, ele.size(), sum);
}

int main() {
    vector<int> ele = {1, 2, 3};
    int sum = 4;
    cout << count(ele, sum);
    return 0;
}