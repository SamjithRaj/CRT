#include<bits/stdc++.h>
using namespace std;

class dictionary{
    map<int, vector<int>> d;
public:
    void insert(int key, int value){
        d[key].push_back(value);
    }
    void remove(int key){
        d.erase(key);
    }
    map<int, vector<int>> getD(){
        return d;
    }
};

void dfs(int u, map<int, vector<int>> &graph, map<int, bool> &visited, stack<int> &s){
    visited[u] = true;
    for(int v : graph[u]){
        if(!visited[v]) dfs(v, graph, visited, s);
    }
    s.push(u);
}

int topologicalSort(dictionary &dict){
    map<int, vector<int>> graph = dict.getD();
    map<int, bool> visited;
    stack<int> s;
    set<int> nodes;
    for(auto i : graph){
        nodes.insert(i.first);
        for(auto j : i.second) nodes.insert(j);
    }
    for(auto i : nodes){
        if(!visited[i]) dfs(i, graph, visited, s);
    }
    cout << "Topological Sort: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}

int main(){
    dictionary dict;
    dict.insert(1, 2);
    dict.insert(1, 3);
    dict.insert(2, 4);
    dict.insert(3, 4);
    dict.insert(5, 3);
    dict.insert(5, 4);
    topologicalSort(dict);
    return 0;
}
