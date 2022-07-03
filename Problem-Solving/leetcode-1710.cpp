// Maximum Units on a truck

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> A, vector<int> B) { return A[1] > B[1]; }

class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);

        int boxes = 0;

        for (auto x : boxTypes) {
            if (truckSize == 0) break;

            if (truckSize - x[0] >= 0) {
                boxes += x[1] * x[0];
                truckSize -= x[0];
            } else if (truckSize != 0 and truckSize - x[0] < 0) {
                boxes += truckSize * x[1];
                break;
            }
        }

        return boxes;
    }
};

int main() {
    Solution s;
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    cout << s.maximumUnits(boxTypes, truckSize);
}