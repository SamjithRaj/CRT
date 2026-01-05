#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int sx, sy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                sx = i;
                sy = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    vector<vector<int>> d(n, vector<int>(m, -1));
    d[sx][sy] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        if(a[x][y] == 3){
            cout << "Shortest Path: " << d[x][y] << endl;
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(d[nx][ny] == -1 && (a[nx][ny] == 1 || a[nx][ny] == 3)){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << "No Path Found" << endl;
    return 0;
}