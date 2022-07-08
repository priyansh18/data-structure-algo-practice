#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long int findMaxProduct(vector<int>& a, int n) {
        // Write your code here
        int max_negative = 0;
        int negative_count = 0;
        long long int product = 1;
        const int M = 1e9 + 7;
        for (auto x : a) {
            if (x == 0) continue;
            if (x < 0) {
                max_negative = max(max_negative, x);
                negative_count++;
            }
            product = (product * x) % M;
        }

        if (negative_count % 2 != 0) {
            cout << "wewtshrdyt";
            product = product / max_negative;
        }

        return max(0ll, product) % M;
    }
};

int main() {
    Solution s;
    vector<int> a = {-1, -2, -3, -4, -5,-6, 1, 2, 3, 4, 5};
    int n = a.size();
    cout << s.findMaxProduct(a, n);
}