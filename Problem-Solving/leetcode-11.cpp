// Container with most water.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;

        while (i < j) {
            ans = max(ans, (j - i) * (min(height[j], height[i])));
            height[i] < height[j] ? i++ : j--;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height) << endl;
}
