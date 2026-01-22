#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
int min_dist = INT_MAX;
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

void findMinPath(int x, int y, int dx, int dy, int dist, vector<vector<bool>> &visited) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || visited[x][y]) {
        return;
    }
    if (x == dx && y == dy) {
        min_dist = min(min_dist, dist);
        return;
    }
    visited[x][y] = true;
    findMinPath(x + 1, y, dx, dy, dist + 1, visited);
    findMinPath(x - 1, y, dx, dy, dist + 1, visited);
    findMinPath(x, y + 1, dx, dy, dist + 1, visited);
    findMinPath(x, y - 1, dx, dy, dist + 1, visited);
    visited[x][y] = false;
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

    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    findMinPath(sx, sy, dx, dy, 0, vis2);

    cout << nodes_count << endl;
    if (min_dist == INT_MAX) cout << -1 << endl;
    else cout << min_dist << endl;

    return 0;
}