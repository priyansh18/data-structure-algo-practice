// Buy and sell stock III

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> left(n), right(n);

        // For first transaction.
        int leftMin = prices[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        // for second transaction.
        int rightMax = prices[n - 1];
        for (int j = n - 2; j >= 0; j++) {
            right[j] = max(right[j + 1], rightMax - prices[j]);
            rightMax = max(rightMax, prices[j]);
        }

        int profit = right[0];
        for (int i = 1; i < n; i++) {
            profit = max(profit, left[i - 1] + right[i]);
        }

        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {1, 2, 3, 4, 5};
    cout << s.maxProfit(prices);
}