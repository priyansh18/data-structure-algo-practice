// Basically used to detect strongly connected components in the graph.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> graph[N], reverseGraph[N];

vector<int> order;

int visited[N], color[N];

// Topological Sorting
void dfs1(int src) {
    visited[src] = 1;
    for (auto node : graph[src]) {
        if (!visited[node]) dfs1(node);
    }

    order.push_back(src);
}

void dfs2(int src, int component) {
    visited[src] = 1;
    color[src] = component;
    for (auto node : reverseGraph[src]) {
        if (!visited[node]) dfs2(node, component);
    }
}

int main() {
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        // Graph is Directed
        graph[x].push_back(y);
        reverseGraph[y].push_back(x);
    }

    // Traversing every vertex if not visited.
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) dfs1(i);
    }

    reverse(order.begin(), order.end());

    // Marking Visited node as 0 to perform next dfs

    memset(visited, 0, sizeof(visited));

    int component = 1;

    for (auto x : order)
        if (!visited[x]) dfs2(x, component++);

    for (int i = 1; i <= v; i++) {
        cout << i << " " << color[i] << endl;
    }

    cout << "Total Number of Components are : " << component - 1 << endl;

    return 0;
}