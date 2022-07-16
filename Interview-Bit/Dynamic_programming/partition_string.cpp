#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ways(string& str, int n, int i, int minLength, int k) {
        if (k == 1 and i == n) return 1;
        if (k > 1 and i == n) return 0;

        if ((str[i] - '0') & 1) return 0;

        int digitI = str[i] - '0';
        int ans = 0;
        for (int j = i + 1; j < n; j++) {
            int digitJ = str[j] - '0';
            if (digitI % 2 == 0 and digitJ % 2 != 0 and j - i + 1 >= minLength) {
                ans += ways(str, n, j + 1, minLength, k - 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    string str = "232387421";
    int m = 2;
    int n = 9;
    int k = 3;
    cout << s.ways(str, n, 0, m, k);
}