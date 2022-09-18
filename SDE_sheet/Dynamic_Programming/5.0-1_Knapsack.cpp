// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int dp[1001][1001];
    // Function to return max value that can be put in knapsack of capacity W.
    int helper(int wt[], int val[], int w, int n) {
        // Include the current weight
        if (w == 0 or n == 0) return 0;

        if (dp[w][n] != -1) return dp[w][n];

        int inc = 0;
        if (w - wt[n - 1] >= 0) {
            inc = val[n - 1] + helper(wt, val, w - wt[n - 1], n - 1);
        }

        // Exclude the current weight
        int exc = helper(wt, val, w, n - 1);

        return dp[w][n] = max(inc, exc);
    }

    int knapSack(int W, int wt[], int val[], int n) {
        // Your code here
        memset(dp, -1, sizeof(dp));
        return helper(wt, val, W, n);
    }
};

// { Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++) cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++) cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}  // } Driver Code Ends