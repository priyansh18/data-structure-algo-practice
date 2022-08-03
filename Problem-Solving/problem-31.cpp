// Minimum No of operations to reach from start to end;
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(int start, int end, vector<int> arr) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (node == end) return steps;
            for (auto x : arr) {
                int dest = node * x;
                if (dest <= end) {
                    q.push({dest, steps + 1});
                }
            }
        }

        return -1;
    }

    int minOp(int start, int end, vector<int> arr) {
        if (start > end) return 1e9;
        if (start == end) return 0;
        int k = 1e9;
        for (auto x : arr) {
            k = min(k, minOp(start * x, end, arr) + 1);
        }

        return k;
    }
};

int main() {
    Solution s;
    int start = 2;
    int end = 100;
    vector<int> arr = {2, 5, 10};
    cout << s.minOperations(start, end, arr);
    cout << endl;
    cout << s.minOp(start, end, arr);
}