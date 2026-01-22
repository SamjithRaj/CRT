#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> dp;
int nodes_count = 0;

void countSubtree(int x, int y, vector<vector<bool>> &visited) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    nodes_count++;
    countSubtree(x + 1, y, visited);
    countSubtree(x - 1, y, visited);
    countSubtree(x, y + 1, visited);
    countSubtree(x, y - 1, visited);
}

void findMinPath(int x, int y, int dx, int dy, int dist) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return;
    }
    if (dist >= dp[x][y]) return;
    dp[x][y] = dist;
    if (x == dx && y == dy) {
        return;
    }
    findMinPath(x + 1, y, dx, dy, dist + 1);
    findMinPath(x - 1, y, dx, dy, dist + 1);
    findMinPath(x, y + 1, dx, dy, dist + 1);
    findMinPath(x, y - 1, dx, dy, dist + 1);
}

void findMaxPath(int x, int y, int dx, int dy, int dist) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return;
    }
    if (dist <= dp[x][y]) return;
    dp[x][y] = dist;
    if (x == dx && y == dy) {
        return;
    }
    findMaxPath(x + 1, y, dx, dy, dist + 1);
    findMaxPath(x - 1, y, dx, dy, dist + 1);
    findMaxPath(x, y + 1, dx, dy, dist + 1);
    findMaxPath(x, y - 1, dx, dy, dist + 1);
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    countSubtree(sx, sy, vis1);

    dp.assign(n, vector<int>(m, INT_MAX));
    findMinPath(sx, sy, dx, dy, 0);
    findMaxPath(sx, sy, dx, dy, 0);

    cout << nodes_count << endl;
    if (dp[dx][dy] == INT_MAX) cout << -1 << endl;
    else cout << dp[dx][dy] << endl;

    return 0;
}