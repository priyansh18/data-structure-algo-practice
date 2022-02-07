#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

void print_sequence(string s1, string s2, int i, int j,
                    vector<vector<int>> dp) {
    vector<char> result;

    while (i != 0 and j != 0) {
        if (dp[i][j] == dp[i - 1][j - 1]) {
            j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            result.push_back(s1[i - 1]);
            i--;
            j--;
        }
    }

    reverse(result.begin(), result.end());
    for (char x : result) {
        cout << x << " ";
    }
}

int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if (s1[i] == '\0' or s2[j] == '\0') {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s1[i] == s2[j]) return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);

    return dp[i][j] = max(lcs(s1, s2, i + 1, j, dp), lcs(s1, s2, i, j + 1, dp));
}

int lcs_bottom_up(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    print_sequence(s1, s2, n1, n2, dp);

    cout << endl;

    return dp[n1][n2];
}

int main() {
    string s1 = "abcd";
    string s2 = "abedg";
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout << lcs(s1, s2, 0, 0, dp) << endl;

    cout << lcs_bottom_up(s1, s2) << endl;
}
