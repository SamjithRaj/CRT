#include<bits/stdc++.h>
using namespace std;

int topologicalSort(vector<vector<int>> &graph, int n){
    vector<int> inorder(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 1) inorder[j]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inorder[i] == 0) q.push(i);
    }
    cout << "Topological Sort: ";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v = 1; v <= n; v++){
            if(graph[u][v] == 1){
                inorder[v]--;
                if(inorder[v] == 0) q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}

int main(){
    int n = 5;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    graph[5][3] = 1;
    graph[5][4] = 1;
    topologicalSort(graph, n);
    return 0;
}
