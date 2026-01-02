#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    int totalWeight = 0;
    for (int i = 1; i < graph.size(); i++)
        totalWeight += graph[parent[i]][i];
    cout << "Total Minimum Weight: " << totalWeight << endl;
}

void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
  	vector<vector<int>> graph = { { 0, 6, 1, 1, 0, 0, 2 },
                        		{6, 0, 2, 0,0,3,0},{1,2,0,4,0,2,0 },
                        		{ 1,0,4,0,3,0,0},
                        		{ 0, 0, 0, 3, 0, 1, 1 },
                        		{ 0, 3, 2, 0, 1, 0, 0 },
                                { 2, 0, 0, 0, 1, 0, 0 }
                             };

    primMST(graph);

    return 0;
}