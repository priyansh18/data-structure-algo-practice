#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<vector<int>>& v, int src, vector<int>& visited) {
        visited[src] = 1;
        for (auto nbr : v[src]) {
            if (!visited[nbr]) {
                dfs(v, nbr, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> v(n);
        int edges = connections.size();
        if (edges < n - 1) return -1;

        for (auto x : connections) {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        vector<int> visited(n, 0);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(v, i, visited);
            }
        }

        return components - 1;
    }
};
int main() {
    Solution s;
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << s.makeConnected(n, connections) << endl;
}