#include <bits/stdc++.h>
using namespace std;

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
};

int main() {
    Solution s;
    int n = 6;
    int arr[n] = {0900, 0940, 0950, 1100, 1500, 1800};
    int dep[n] = {0910, 1200, 1120, 1130, 1900, 2000};
    cout << s.findPlatform(arr, dep, n);
}