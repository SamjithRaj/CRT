#include<bits/stdc++.h>
using namespace std;


struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(int i, vector<int> &parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &ranks) {
    int root_u = find(u, parent);
    int root_v = find(v, parent);
    if (root_u != root_v) {
        if (ranks[root_u] < ranks[root_v])
            parent[root_u] = root_v;
        else if (ranks[root_u] > ranks[root_v])
            parent[root_v] = root_u;
        else {
            parent[root_v] = root_u;
            ranks[root_u]++;
        }
    }
}

int KruskalMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<Edge> edges;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] != 0)
                edges.push_back({i, j, graph[i][j]});

    sort(edges.begin(), edges.end());

    vector<int> parent(V), ranks(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalWeight = 0;
    for (const auto& edge : edges) {
        if (find(edge.u, parent) != find(edge.v, parent)) {
            totalWeight += edge.weight;
            unionSet(edge.u, edge.v, parent, ranks);
        }
    }
    cout << "Total Minimum Weight: " << totalWeight << endl;
    return 0;
}

int main() {
    vector<vector<int>> graph = { { 0, 6, 1, 1, 0, 0, 2 },
                        		{6, 0, 2, 0,0,3,0},{1,2,0,4,0,2,0 },
                        		{ 1,0,4,0,3,0,0},
                        		{ 0, 0, 0, 3, 0, 1, 1 },
                        		{ 0, 3, 2, 0, 1, 0, 0 },
                                { 2, 0, 0, 0, 1, 0, 0 }
                             };

    KruskalMST(graph);

    return 0;
}