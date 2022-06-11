// Is Power of 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPowerOfTwo(int n) {
        long long x = n;
        if (x == 0) return false;
        return (x & (x - 1)) == 0;
    }
};

int main() {
    Solution s;
    int n = 128;
    cout << s.isPowerOfTwo(n);
}