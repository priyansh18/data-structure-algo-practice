#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> graph[N];

vector<pair<int, int>> bridges;
set<int> articulations;

int visited[N], discovered[N], lowest[N], tme = 1;

void dfs(int src, int parent) {
    visited[src] = 1;
    discovered[src] = lowest[src] = tme++;
    int child = 0;

    for (auto node : graph[src]) {
        if (!visited[node]) {
            dfs(node, src);
            child++;
            // We already know lowest and discovered tm of node.
            lowest[src] = min(lowest[src], lowest[node]);

            // Bridge
            if (lowest[node] > discovered[src]) {
                bridges.push_back({src, node});
            }

            // Articulation Points
            if (parent != 0 and lowest[node] >= discovered[src]) {
                articulations.insert({src, node});
            }

        } else if (node != parent) {
            // Backedge
            lowest[src] = min(lowest[src], discovered[node]);
        }
    }

    // If root is an articulation point or not
    if (parent == 0 and child > 1) {
        articulations.insert(src);
    }

    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(y);
    }

    dfs(1, 0);

    for (auto x : articulations) {
        cout << x << ",";
    }

    return 0;
}