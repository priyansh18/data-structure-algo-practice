// Critical Connection in a network.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
    
                                            }
};

int main() {
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int n = 4;
    vector<vector<int>> result = s.criticalConnections(n, connections);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}