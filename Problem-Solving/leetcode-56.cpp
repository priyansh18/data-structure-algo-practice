// Merging Overlapping Intervals.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if (intervals.size() == 0) {
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempIntervals = intervals[0];

        for (auto it : intervals) {
            if (it[0] <= tempIntervals[1]) {
                tempIntervals[1] = max(it[1], tempIntervals[1]);
            } else {
                mergedIntervals.push_back(tempIntervals);
                tempIntervals = it;
            }
        }

        mergedIntervals.push_back(tempIntervals);
        return mergedIntervals;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = s.merge(intervals);

    for (auto x : result) {
        cout << x[0] << " and " << x[1] << endl;
    }
}