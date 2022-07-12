// Count Unreachable Pairs of Nodes in an Undirected Graph

class Solution {
public:
    void dfs(vector<vector<int>> &v, int src, vector<int> &visited, int &node) {
        visited[src] = 1;
        for (auto nbr : v[src]) {
            if (!visited[nbr]) {
                node++;
                dfs(v, nbr, visited, node);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for (auto x : edges) {
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
        
        long long ans = (long long)n*(n - 1) / 2ll;
        for (auto x : nodes) {
            ans -= (long long)x*(x - 1) / 2ll;
        }

        return ans;
        
    }
};