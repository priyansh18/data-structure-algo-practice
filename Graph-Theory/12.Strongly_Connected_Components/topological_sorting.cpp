#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> graph[N];
int visited[N];
vector<int> order;

void dfs(int src, int parent) {
    visited[src] = 1;

    for (auto node : graph[src]) {
        if (!visited[node]) {
            dfs(node, src);
        }
    }

    order.push_back(src);
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
        // graph[y].push_back(x);
    }

    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }

    reverse(order.begin(), order.end());

    for (auto x : order) {
        cout << x << ",";
    }

    return 0;
}