#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    int extraEdges = 0;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int nodeCount = 0;
            int edgeCount = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                nodeCount++;
                for(int v : adj[u]){
                    edgeCount++;
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            extraEdges += (edgeCount / 2) - (nodeCount - 1);
        }
    }

    cout << "Extra Edges: " << extraEdges << endl;
    if(extraEdges >= components - 1){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}