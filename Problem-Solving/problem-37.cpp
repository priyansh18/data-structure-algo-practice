// Minimum Platform

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Your code here
        vector<vector<int>> timings;
        for (int i = 0; i < n; i++) {
            timings.push_back({arr[i], dep[i]});
        }

        sort(timings.begin(), timings.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(timings[0][1]);
        for (int i = 1; i < timings.size(); i++) {
            if (pq.top() < timings[i][0]) {
                pq.pop();
                pq.push(timings[i][1]);
            } else {
                pq.push(timings[i][1]);
            }
        }

        return pq.size();
    }

    int findPlatform(int arr[], int dep[], int n) {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms = 1;
        int maxPlatform = 1;
        int i = 1;
        int j = 0;
        while (i < n and j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            maxPlatform = max(maxPlatform, platforms);
        }

        return maxPlatform;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}  // } Driver Code Ends