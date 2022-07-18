// Koko Eating Bananas

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canKokoEatBananaInTime(vector<int>& piles, int h, long long mid) {
        long long hours = 0;
        for (auto x : piles) {
            hours += (x + mid - 1) / mid;
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long low = 1;
        long long high = 0;
        for (auto x : piles) {
            high += x;
        }
        long long ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canKokoEatBananaInTime(piles, h, mid)) {
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
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    cout << s.minEatingSpeed(piles, h);
}