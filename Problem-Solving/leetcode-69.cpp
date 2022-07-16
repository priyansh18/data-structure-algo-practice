// Square root

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        int ans;
        while (s <= e) {
            long mid = s + (e - s) / 2;

            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                ans = mid;
                s = mid + 1;

            } else {
                e = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(18);
}