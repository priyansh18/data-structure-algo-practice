// Minimum no of arrows to burst all ballons.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static bool compare(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), compare);
        int arrow = 1;
        int currentEnd = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > currentEnd) {
                arrow++;
                currentEnd = points[i][1];
            }
        }
        return arrow;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << s.findMinArrowShots(points) << endl;
}