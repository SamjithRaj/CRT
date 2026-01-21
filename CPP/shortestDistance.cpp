#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        for(int v : graph[u]){
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
    }

    if(topoOrder.size() != n){
        cout << "Graph has a cycle, topological sort not possible." << endl;
    } else {
        cout << "Topological Sort Order: ";
        for(int node : topoOrder){
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}