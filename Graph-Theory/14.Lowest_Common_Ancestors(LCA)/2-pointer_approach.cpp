#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> graph[N];
int depth[N], par[N];

void dfs(int src, int parent) {
    par[src] = parent;
    depth[src] = depth[parent] + 1;
    for (auto x : graph[src]) {
        if (x != parent) {
            dfs(x, src);
        }
    }
}

int lca(int v1, int v2) {
    if (v1 == v2) {
        return v1;
    }

    int i, j;
    if (depth[v1] > depth[v2]) {
        i = v1;
        j = v2;
    } else {
        i = v2;
        j = v1;
    }

    int diff = depth[i] - depth[j];

    while (diff--) {
        i = par[i];
    }

    while (i != j) {
        i = par[i];
        j = par[j];
    }

    return i;
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

    dfs(1, 0);

    int t;
    cin >> t;

    while (t--) {
        int v1, v2;
        cin >> v1 >> v2;

        cout << "Lowest Common Ancestor is : " << lca(v1, v2) << "\n";
    }

    return 0;
}