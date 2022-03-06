#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int src, vector<vector<int>> edges, int vertices) {
    vector<int> dist(vertices + 1, INT_MAX);
    dist[src] = 0;

    // Relaxing Edges V-1 times
    int d = vertices - 1;
    while (d--) {
        for (auto x : edges) {
            if (dist[x[0]] != INT_MAX and dist[x[0]] + x[2] < dist[x[1]]) {
                dist[x[1]] = dist[x[0]] + x[2];
            }
        }
    }
    // Negative Weight Cycle
    for (auto x : edges) {
        if (dist[x[0]] != INT_MAX and dist[x[0]] + x[2] < dist[x[1]]) {
            cout << "Negative Weight Cycle Found" << endl;
            break;
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    // Edges List
    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<int> weights = bellmanFord(1, edges, V);

    int i = 0;

    for (auto x : weights) {
        if (i == 0) {
            i++;
            continue;
        }
        i++;
        cout << x << ",";
    }
}