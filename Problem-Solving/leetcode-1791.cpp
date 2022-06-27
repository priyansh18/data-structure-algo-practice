// Find Center of star graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> v(n + 2);
        for (auto x : edges) {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }

        for (int i = 1; i <= n + 1; i++) {
            if (v[i].size() == n) return i;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << s.findCenter(edges);
}