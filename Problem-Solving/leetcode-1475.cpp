// Final Prices With a Special Discount in a Shop

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        int n = prices.size();
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty())
                result.push_back(prices[i]);
            else {
                if (prices[i] < s.top()) {
                    while (!s.empty() and prices[i] < s.top()) {
                        s.pop();
                    }
                    if (s.empty())
                        result.push_back(prices[i]);
                    else
                        result.push_back(prices[i] - s.top());

                } else {
                    result.push_back(prices[i] - s.top());
                }
            }
            s.push(prices[i]);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution s;
    vector<int> prices = {8, 4, 6, 2, 3};
    // Question of next smallest element
    vector<int> result = s.finalPrices(prices);
    for (auto x : result) {
        cout << x << ",";
    }
}