#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> graph[N];
int visited[N] = {0};
bool cycle = false;

void is_dfs(int src, int parent) {
    visited[src] = 1;
    for (auto node : graph[src]) {
        if (!visited[node]) {
            is_dfs(node, src);
        } else if (node != parent) {
            cycle = true;
        }
    }
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
        graph[y].push_back(x);
    }

    // If graph components are not all connected

    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            is_dfs(i, 0);
        }
    }

    cycle ? cout << "Cycle Detected" : cout << "Cycle Not Detected";
    return 0;
}