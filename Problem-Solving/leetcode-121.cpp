// Best time to buy and sell stock

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minimum(n);
        vector<int> maximum(n);
        minimum[0] = prices[0];
        maximum[n - 1] = prices[n - 1];
        for (int i = 1; i < n; i++) {
            minimum[i] = min(minimum[i - 1], prices[i]);
        }

        for (int j = n - 2; j >= 0; j--) {
            maximum[j] = max(maximum[j + 1], prices[j]);
        }

        int max_value = INT_MIN;

        for (int i = 0; i < n; i++) {
            max_value = max(maximum[i] - minimum[i], max_value);
        }

        return max_value;
    }

    int maxProfitStackOpt(vector<int>& prices) {
        int n = prices.size();
        stack<int> s;
        if(n==0) return 0;
        s.push(prices[0]);
        int i = 1;
        int max_profit = INT_MIN;
        while (i < n) {
            if (prices[i] < s.top()) {
                s.push(prices[i]);
            } else {
                int profit = prices[i] - s.top();
                max_profit = max(max_profit, profit);
            }
            i++;
        }

        return max_profit == INT_MIN ? 0 : max_profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;
     cout << s.maxProfitStackOpt(prices) << endl;
}