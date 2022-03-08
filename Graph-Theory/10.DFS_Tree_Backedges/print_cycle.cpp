#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> graph[N];
int visited[N], par[N];
bool cycle = false;

void dfs(int src, int parent) {
    visited[src] = 1;
    par[src] = parent;
    for (auto node : graph[src]) {
        if (!visited[node]) {
            dfs(node, src);
        } else if (node != parent and visited[node] == 1) {
            // Cycle Detected or backedge found.
            cycle = true;
            int u = src, v = node;
            while (u != v) {
                cout << u << ",";
                u = par[u];
            }
            cout << u;
            exit(0);
        }
    }

    visited[src] = 2;
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
    }

    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
}