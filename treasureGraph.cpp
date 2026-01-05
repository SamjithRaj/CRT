#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int startX, startY;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                startX = i;
                startY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[startX][startY] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        if(grid[x][y] == 3){
            cout << "Shortest Path: " << dist[x][y] << endl;
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if((grid[nx][ny] == 1 || grid[nx][ny] == 3) && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << "No Path Found" << endl;
    return 0;
}