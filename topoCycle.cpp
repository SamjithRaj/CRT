
#include<bits/stdc++.h>
using namespace std;

int topologicalSort(vector<vector<int>> &graph, int n){
    vector<int> inDegree(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 1) inDegree[j]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    int count = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        count++;
        for(int v = 1; v <= n; v++){
            if(graph[u][v] == 1){
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
        }
    }
    if(count < n){
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Detected" << endl;
    }
    return 0;
}

int main(){
    int n; 
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
    topologicalSort(graph, n);
    return 0;
}
