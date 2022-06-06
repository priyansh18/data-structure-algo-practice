// Min Cost Climbing stairs

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCostClimbingStairsHelper(vector<int>& dp, vector<int> cost, int s,
                                    int e) {
        if (s >=e) {
            return 0;
        }

        if (dp[s] != -1) {
            return dp[s];
        }

        return dp[s] = min(
                   cost[s] + minCostClimbingStairsHelper(dp, cost, s + 1, e),
                   cost[s + 1] +
                       minCostClimbingStairsHelper(dp, cost, s + 2, e));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return minCostClimbingStairsHelper(dp, cost, 0, n-1);

    }
};

int main() {
    Solution s;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbingStairs(cost);
}