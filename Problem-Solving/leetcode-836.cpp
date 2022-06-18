// Rectangles Overlap

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[2] <= rec2[0] or rec1[1] >= rec2[3] or rec1[0] >= rec2[2] or
            rec1[3] <= rec2[1])
            return false;
        return true;
    }
};

int main() {
    Solution s;
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    cout << s.isRectangleOverlap(rec1, rec2);
}