// Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int fib(int n,vector<int> &dp) {
        if (n <= 1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fib(n - 1,dp) + fib(n - 2,dp);
    }

    int findMinFibNo(vector<int> fibNumbers, int k, int s, int e) {
        if (s > e) return 1e9;
        if (k < 0) return 1e9;
        if (k == 0) return 0;

        return min(findMinFibNo(fibNumbers, k - fibNumbers[s], s, e) + 1,
                   findMinFibNo(fibNumbers, k, s + 1, e));
    }

    int findMinFibonacciNumbers(int k) {
        vector<int> fibNumbers;
        int sum = 0;
        vector<int> dp(101, -1);
        for (int i = 1; i < 100; i++) {
            int val = fib(i,dp);
            if(val>k) break;
            fibNumbers.push_back(val);
        }

        return findMinFibNo(fibNumbers, k, 0, fibNumbers.size() - 1);
    }
};


int main() {
    Solution s;
    int k = 19;
    cout << s.findMinFibonacciNumbers(k) << endl;
}