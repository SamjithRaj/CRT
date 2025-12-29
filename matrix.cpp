#include<bits/stdc++.h>
using namespace std;

int colSum(const vector<vector<int>>& matrix, int colIndex) {
    int sum = 0;
    for (const auto& row : matrix) {
        if (colIndex < row.size()) {
            sum += row[colIndex];
        }
    }
    return sum;
}

int main(){
    int m, n; 
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    int Maxsum = INT_MIN, maxIndex = 0;
    for(int j = 0; j < n; j++){
        int currentColSum = colSum(matrix, j);
        if(currentColSum > Maxsum){
            Maxsum = currentColSum;
            maxIndex = j;
        }

    }
    cout << "Col no " << maxIndex + 1 << endl << " col sum " << Maxsum << endl;
}