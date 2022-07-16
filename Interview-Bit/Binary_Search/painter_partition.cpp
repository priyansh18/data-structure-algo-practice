#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int CanBePaintedInTime(int A, int B, vector<int> C, int mid) {
        int n = C.size();
        int painters = 1;
        int current = 0;
        for (int i = 0; i < n; i++) {
            if ((current + C[i]) > mid) {
                current = C[i];
                painters++;
                if (painters > A) return false;
            } else {
                current += C[i];
            }
        }
        return true;
    }

    int paint(int A, int B, vector<int>& C) {
        int n = C.size();
        int low = 0;
        int high = 0;
        int total_length = 0;
        for (auto x : C) {
            total_length += x;
            low = max(low, x);
        }
        int ans = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (CanBePaintedInTime(A, B, C, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans*B);
    }
};

int main() {
    Solution s;
    int A = 10;
    int B = 1;
    vector<int> C = {1, 8, 11, 3};
    cout << s.paint(A, B, C);
}