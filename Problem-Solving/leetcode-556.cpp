// Next Greatest Element III

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }

        reverse(v.begin(), v.end());

        if (!next_permutation(v.begin(), v.end())) return -1;

        long long ans = 0;

        for (auto x : v) ans = ans * 10 + x;

        if (ans > INT_MAX) return -1;

        return ans;
    }
};

int main() {
    Solution s;
    int n = 12;
    cout << s.nextGreaterElement(n) << endl;
}