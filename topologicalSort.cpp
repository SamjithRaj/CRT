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

int topologicalSort(dictionary &dict){
    map<int, vector<int>> graph = dict.getD();
    map<int, int> inorder;
    for(auto i : graph){
        if(inorder.find(i.first) == inorder.end()) inorder[i.first] = 0;
        for(auto j : i.second) inorder[j]++;
    }
    queue<int> q;
    for(auto i : inorder){
        if(i.second == 0) q.push(i.first);
    }
    cout << "Topological Sort: ";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        if(graph.find(u) != graph.end()){
            for(int v : graph[u]){
                inorder[v]--;
                if(inorder[v] == 0) q.push(v);
            }
        }
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
