// All Paths from source to target

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<vector<int>> graph, vector<vector<int>>& result,
             vector<int>& path, int src) {
        path.push_back(src);
        if (src == graph.size() - 1) result.push_back(path);

        for (auto nbr : graph[src]) {
            dfs(graph, result, path, nbr);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        int n = graph.size();
        dfs(graph, result, path, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    vector<vector<int>> result = s.allPathsSourceTarget(graph);
    for (auto x : result) {
        for (auto y : x) {
            cout << y << ",";
        }
        cout << endl;
    }
}