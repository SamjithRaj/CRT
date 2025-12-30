//All connected components

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    map<int, vector<int>> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 1){
                d[i].push_back(j);
            }
        }
    }
    for(auto i : d){
        cout << i.first << " : ";
        for(auto j : i.second) cout << j << " ";
        cout << endl;
    }

    vector<bool> visited(max(n, m), false);
    cout << "Connected Components: " << endl;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cout << "Component: ";
            stack<int> s;
            s.push(i);
            visited[i] = true;
            while(!s.empty()){
                int u = s.top();
                s.pop();
                cout << u << " ";
                for(int v : d[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        s.push(v);
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}