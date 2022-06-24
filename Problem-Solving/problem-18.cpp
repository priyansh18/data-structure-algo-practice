// Journey to the moon

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &v, int src, vector<int> &visited, int &node) {
    visited[src] = 1;
    for (auto nbr : v[src]) {
        if (!visited[nbr]) {
            node++;
            dfs(v, nbr, visited, node);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> v(n);
    for (auto x : astronaut) {
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
    }

    vector<int> nodes;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int node = 1;
            dfs(v, i, visited, node);
            nodes.push_back(node);
        }
    }
    
    int ans = n*(n - 1) / 2;
    for (auto x : nodes) {
        ans -= x*(x - 1) / 2;
    }

    return ans;
}

int main() {
    int n = 4;
    int p = 3;
    vector<vector<int>> astronaut = {{0, 2}};
    cout << journeyToMoon(n, astronaut);
}