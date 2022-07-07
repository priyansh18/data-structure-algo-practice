#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumProduct(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        return max(A[0] * A[1] * A[n - 1], A[n - 1] * A[n - 2] * A[n - 3]);
    }
};

int main() {
    Solution s;
    vector<int> A = {0, -1, 3, 100, 70, 50};
    cout << s.maximumProduct(A);
}