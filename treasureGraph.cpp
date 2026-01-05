#include<bits/stdc++.h>
using namespace std;

int main(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    int X, Y;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                X = i;
                Y = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({X, Y});
    
    vector<vector<int>> distanceMatrix(rows, vector<int>(cols, -1));
    distanceMatrix[X][Y] = 0;

    while(!q.empty()){
        pair<int, int> currentCell = q.front();
        q.pop();
        int currRow = currentCell.first;
        int currCol = currentCell.second;

        if(grid[currRow][currCol] == 3){
            cout << "Shortest Path: " << distanceMatrix[currRow][currCol] << endl;
            return 0;
        }


        if(currRow - 1 >= 0 && distanceMatrix[currRow - 1][currCol] == -1 && (grid[currRow - 1][currCol] == 1 || grid[currRow - 1][currCol] == 3)){
            distanceMatrix[currRow - 1][currCol] = distanceMatrix[currRow][currCol] + 1;
            q.push({currRow - 1, currCol});
        }

        if(currRow + 1 < rows && distanceMatrix[currRow + 1][currCol] == -1 && (grid[currRow + 1][currCol] == 1 || grid[currRow + 1][currCol] == 3)){
            distanceMatrix[currRow + 1][currCol] = distanceMatrix[currRow][currCol] + 1;
            q.push({currRow + 1, currCol});
        }

        if(currCol - 1 >= 0 && distanceMatrix[currRow][currCol - 1] == -1 && (grid[currRow][currCol - 1] == 1 || grid[currRow][currCol - 1] == 3)){
            distanceMatrix[currRow][currCol - 1] = distanceMatrix[currRow][currCol] + 1;
            q.push({currRow, currCol - 1});
        }
        if(currCol + 1 < cols && distanceMatrix[currRow][currCol + 1] == -1 && (grid[currRow][currCol + 1] == 1 || grid[currRow][currCol + 1] == 3)){
            distanceMatrix[currRow][currCol + 1] = distanceMatrix[currRow][currCol] + 1;
            q.push({currRow, currCol + 1});
        }
    }
    cout << "No Path Found" << endl;
    return 0;
}