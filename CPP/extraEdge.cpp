#include<bits/stdc++.h>
using namespace std; 

int find(int i, vector<int> &parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &size) {
    int root_u = find(u, parent);
    int root_v = find(v, parent);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    vector<int> size(n, 1);
    for(int i = 0; i < n; i++) parent[i] = i;

    int extraEdges = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(find(u, parent) == find(v, parent)){
            extraEdges++;
        } else {
            unionSet(u, v, parent, size);
        }
    }

    int components = 0;
    for(int i = 0; i < n; i++){
        if(parent[i] == i) components++;
    }

    cout << "Extra Edges: " << extraEdges << endl;
    if(extraEdges >= components - 1){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}