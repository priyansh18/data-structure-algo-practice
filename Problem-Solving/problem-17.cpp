// Facing the sun

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countBuildings(int h[], int n) {
        int count = 1;
        int maxSum = h[0];
        for (int i = 1; i < n; i++) {
            if (h[i] > maxSum) {
                count++;
            }
            maxSum = max(maxSum, h[i]);
        }

        return count;
    }
};

int main() {
    Solution s;
    int n = 5;
    int h[] = {7, 4, 2, 8, 9};
    cout << s.countBuildings(h, n);
}