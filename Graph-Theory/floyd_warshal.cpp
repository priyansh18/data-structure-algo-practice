#include <bits/stdc++.h>
using namespace std;

#define INF 10000

vector<vector<int>> floydWarshall(vector<vector<int>> graph) {

    vector<vector<int>> dist(graph);

    int V = graph.size();

    // In kth phases , We include vertices (1,2,3,--------,k) as intermediate
    // vertices
    for (int k = 0; k < V; k++) {
        // Iterate over entire 2D Matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // if vertex k can be included and can we minimise the dist ?
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> graph = {{0, INF, -2, INF},
                                 {4, 0, 3, INF},
                                 {INF, INF, 0, 2},
                                 {INF, -1, INF, 0}};

    auto result = floydWarshall(graph);

    for (auto x : result) {
        for (auto y : x) {
            cout << y << ",";
        }
        cout << endl;
    }
}