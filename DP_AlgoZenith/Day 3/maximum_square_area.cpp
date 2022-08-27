
// Approach 1 - Iterative Dp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
int dp[1005][1005];

int maxSquareArea() {
    // Initialzing first row and col with grid value
    for (int i = 0; i < n; i++) {
        dp[i][0] = grid[i][0];
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = grid[0][j];
    }

    // Filling up of dp
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] =
                    1 + min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
            }
        }
    }

    // Finding Max Element of all.
    int maxEl = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxEl = max(maxEl, dp[i][j]);
        }
    }

    // Returning the area.
    return maxEl * maxEl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) {
            grid[i].resize(m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                dp[i][j] = 0;
            }
        }
        cout << maxSquareArea() << endl;
    }

    return 0;
}

// Approach 2 - Recursive Dp

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
int dp[1005][1005];

int rec(int i, int j) {
    // pruning
    //    base case
    if (i == 0 and j == 0) return dp[i][j] = grid[i][j];

    // cache check
    if (dp[i][j] != -1) return dp[i][j];

    // computing

    int ans1 = 1e9;
    int ans2 = 1e9;
    int ans3 = 1e9;

    if (i - 1 >= 0 and j - 1 >= 0) {
        ans1 = rec(i - 1, j - 1);
    }
    if (j - 1 >= 0) {
        ans2 = rec(i, j - 1);
    }
    if (i - 1 >= 0) {
        ans3 = rec(i - 1, j);
    }

    // save and return
    if (grid[i][j] == 0) return dp[i][j] = 0;
    if (ans1 == 1e9 or ans2 == 1e9 or ans3 == 1e9) return dp[i][j] = 1;

    return dp[i][j] = min({ans1, ans2, ans3}) + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) {
            grid[i].resize(m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                dp[i][j] = -1;
            }
        }
        rec(n - 1, m - 1);
        int maxEl = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << dp[i][j] << ",";
                maxEl = max(maxEl, dp[i][j]);
            }
            // cout << endl;
        }

        cout << maxEl * maxEl << endl;
    }

    return 0;
}