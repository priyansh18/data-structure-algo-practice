// Power of Number pow(X,n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == INT_MAX) {
            return x;
        } else if (n == INT_MIN)
            return (x == 1 || x == -1) ? 1 : 0;
        if (n < 0) x = 1 / x, n *= -1;
        double ans = 1;
        while (n > 0) {
            if (n & 1) ans *= x;
            x = x * x;
            n = n >> 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    double x = 2.00000;
    int n = -2;
    cout << s.myPow(x, n) << endl;
}