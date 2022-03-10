#include <bits/stdc++.h>
using namespace std;

// Lca optimize i.e. Insted of traversing every parent of the node which is O(n)
// complexity , It uses O(logn) Complexity.

const int N = 1e5 + 1, M = 20;

vector<int> graph[N];
int depth[N], par[N][M];

void dfs(int src, int parent) {
    depth[src] = depth[parent] + 1;
    par[src][0] = parent;
    for (int j = 1; j < M; j++) {
        // Dynamic Programic Approach to fill all the table associated with it.
        par[src][j] = par[par[src][j - 1]][j - 1];
    }
    for (auto x : graph[src]) {
        if (x != parent) {
            dfs(x, src);
        }
    }
}

int lca(int u, int v) {
    if (u == v) {
        return u;
    }

    int i, j;

    if (depth[u] > depth[v]) {
        i = u;
        j = v;
    } else {
        i = v;
        j = u;
    }

    int diff = depth[i] - depth[j];

    for (int k = M - 1; k >= 0; k--) {
        if ((diff >> k) & 1) {
            // Jth bit is set
            i = par[i][k];
        }
    }

    if (i == j) {
        return i;
    }

    for (int k = M - 1; k >= 0; k--) {
        if (par[i][k] != par[j][k]) {
            cout << "dferngt";
            i = par[i][k];
            j = par[j][k];
        }
    }
    cout << i << " sdf " << j << endl;

    return par[i][0];
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
        int u, v;
        cin >> u >> v;
        cout << "Lowest Common Ancestor is : " << lca(u, v) << "\n";
    }

    return 0;
}