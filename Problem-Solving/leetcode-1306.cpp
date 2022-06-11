// Jump Game III

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canReachHelper(vector<int> &arr, int s, int e, vector<int> &visited) {
        if (s < 0 or s > e) return false;
        if (arr[s] == 0) return true;
        if (!visited[s]) {
            visited[s] = 1;
            if (canReachHelper(arr, s - arr[s], e, visited) or
                canReachHelper(arr, s + arr[s], e, visited)) {
                return true;
            }
            visited[s] = 0;
        }
        return false;
    }

    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);
        return canReachHelper(arr, start, n - 1, visited);
    }
};

int main() {
    Solution s;
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    cout << s.canReach(arr, 5);
}