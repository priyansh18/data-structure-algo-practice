// Happy Number

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int squareNumber(int x) {
        int ans = 0;
        while (x != 0) {
            ans += (x % 10) * (x % 10);
            x = x / 10;
        }
        return ans;
    }

    bool helper(map<int, bool>& m, int n) {
        if (n == 1) return true;
        if (m.count(squareNumber(n)) != 0) return false;
        m[squareNumber(n)] = 1;
        return helper(m, squareNumber(n));
    }

    bool isHappy(int n) {
        map<int, bool> m;
        return helper(m, n);
    }
};

int main() {
    Solution s;
    int n = 2;
    cout << s.isHappy(n);
}