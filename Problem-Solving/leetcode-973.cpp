// K Closest Point to origin.

#include <bits/stdc++.h>
using namespace std;

#define pvif pair<vector<int>, float>

class Compare {
   public:
    bool operator()(pvif A, pvif B) {
        if (A.second == B.second) {
            return A.second > B.second;
        }
        return A.second > B.second;
    }
};

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pvif, vector<pvif>, Compare> minHeap;

        for (auto x : points) {
            float eucDist = sqrt(x[0]*x[0] + x[1]*x[1]);
            cout << eucDist << endl;
            minHeap.push({x, eucDist});
        }

        while (k--) {
            auto el = minHeap.top();
            minHeap.pop();
            result.push_back(el.first);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{3, 3}, {5, -1},{-2,4}};
    vector<vector<int>> result = s.kClosest(points, 2);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}