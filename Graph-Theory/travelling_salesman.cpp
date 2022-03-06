#include <bits/stdc++.h>
using namespace std;

int travellingSalesman(vector<vector<int>> dist, int setOfCities, int city,
                       int n, vector<vector<int>> &dp) {
    // Base Case
    if (setOfCities == (1 << n) - 1) {
        return dist[city][0];
    }

    if (dp[setOfCities][city] != -1) {
        return dp[setOfCities][city];
    }

    // otherwise try all possible options

    int ans = INT_MAX;
    for (int choice = 0; choice < n; choice++) {
        if ((setOfCities & (1 << choice)) == 0) {
            int subProb = dist[city][choice] +
                          travellingSalesman(dist, setOfCities | (1 << choice),
                                             choice, n, dp);
            ans = min(ans, subProb);
        }
    }

    dp[setOfCities][city] = ans;
    return ans;
}

int main() {
    vector<vector<int>> dist = {
        {0, 20, 42, 25}, {20, 0, 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};

    int n = 4;

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << travellingSalesman(dist, 1, 0, n, dp) << endl;

    for (auto x : dp) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}