// Maximal Network Rank

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<set<int>> v(n);
        for (auto x : roads) {
            v[x[0]].insert(x[1]);
            v[x[1]].insert(x[0]);
        }

        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto nbr : v[i]) {
                inDegree[nbr]++;
            }
        }

        int maxAns = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i].count(j) == 0) {
                    maxAns = max(maxAns, inDegree[i] + inDegree[j]);
                } else {
                    maxAns = max(maxAns, inDegree[i] + inDegree[j] - 1);
                }
            }
        }

        return maxAns;
    }
};

int main() {
    Solution s;
    int n = 8;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3},
                                 {2, 4}, {5, 6}, {5, 7}};
    cout << s.maximalNetworkRank(n, roads) << endl;
}