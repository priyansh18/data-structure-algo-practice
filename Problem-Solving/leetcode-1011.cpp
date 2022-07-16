// Capacity to ship package within D days

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canBePlacedOnShip(vector<int> weights, int days, int mid) {
        int n = weights.size();
        int d = 1;
        int total_weight = 0;
        for (int i = 0; i < n; i++) {
            if (total_weight + weights[i] > mid) {
                total_weight = weights[i];
                d++;
                if (d > days) return false;
            } else {
                total_weight += weights[i];
            }
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0;
        int high = 0;
        int total_weight = 0;
        for (auto x : weights) {
            total_weight += x;
            low = max(low, x);
        }
        high = total_weight;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canBePlacedOnShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << s.shipWithinDays(weights, days);
}


