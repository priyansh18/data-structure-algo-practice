// Longest Palindromic Substring.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = 1;
        }

        for (int d = 2; d < n; d++) {
            int i = 0;
            int j = d;
            while (i < n and j < n) {
                if (s[i] == s[j] and i + 1 < n and dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                }
                i++;
                j++;
            }
        }
        int maxLength = 0;
        string output = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j]) {
                    if (maxLength < j - i + 1) {
                        maxLength = j - i + 1;
                        output = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return output;
    }
};

int main() {
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str);
}