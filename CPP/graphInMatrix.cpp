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
    return 0;
}