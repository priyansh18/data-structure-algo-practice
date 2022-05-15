// Fibonacci Number

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int fib(int n) {
        if (n == 0 or n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.fib(n);
}