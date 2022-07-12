// Matchstick to square.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool helper(vector<int>& matchsticks, int i, int sum1, int sum2, int sum3,
                int sum4, int target) {
        if (sum1 > target or sum2 > target or sum3 > target or sum4 > target)
            return false;
        if (i == -1 and sum1 == target or sum2 == target or sum3 == target or
            sum4 == target)
            return true;

        return helper(matchsticks, i - 1, sum1 + matchsticks[i], sum2, sum3,
                      sum4, target) or
               helper(matchsticks, i - 1, sum1, sum2 + matchsticks[i], sum3,
                      sum4, target) or
               helper(matchsticks, i - 1, sum1, sum2, sum3 + matchsticks[i],
                      sum4, target) or
               helper(matchsticks, i - 1, sum1, sum2, sum3,
                      sum4 + matchsticks[i], target);
    }

    bool makesquare(vector<int>& matchsticks) {
        int parametre = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (parametre % 4 != 0 and matchsticks.size() < 4) return false;
        int lengthOfOneSide = parametre / 4;
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

        return helper(matchsticks, matchsticks.size() - 1, sum1, sum2, sum3,
                      sum4, lengthOfOneSide);
    }
};

class Solution {
   public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        
        const int perimeter =
            accumulate(begin(matchsticks), end(matchsticks), 0);
        if (perimeter % 4 != 0) return false;

        sort(begin(matchsticks), end(matchsticks), greater<int>());
        return dfs(matchsticks, 0, vector<int>(4, perimeter / 4));
    }

   private:
    bool dfs(const vector<int>& matchsticks, int selected,
             vector<int>&& edges) {
        if (selected == matchsticks.size())
            return all_of(begin(edges), end(edges),
                          [](int edge) { return edge == 0; });

        for (int i = 0; i < 4; ++i) {
            if (matchsticks[selected] > edges[i]) continue;
            edges[i] -= matchsticks[selected];
            if (dfs(matchsticks, selected + 1, move(edges))) return true;
            edges[i] += matchsticks[selected];
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> matchsticks = {1, 1, 2, 2, 2};
    cout << s.makesquare(matchsticks);
}