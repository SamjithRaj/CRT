#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n, m; 
    cin >> n >> m; 
    
    vector<int> dist(n * n, INFINITY);
    for(int i = 0; i < n; i++) dist[i * n + i] = 0;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u * n + v] = w;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i * n + k] != INFINITY && dist[k * n + j] != INFINITY){
                    dist[i * n + j] = min(dist[i * n + j], dist[i * n + k] + dist[k * n + j]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i * n + j] == INFINITY) cout << "INF ";
            else cout << dist[i * n + j] << " ";
        }
        cout << endl;
    }
    return 0;
}