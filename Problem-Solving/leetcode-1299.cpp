// Replace Elements with Greatest Element on Right Side

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n, -1);

        for (int i = n - 2; i >= 0; i--) {
            prefix[i] = max(arr[i + 1], prefix[i + 1]);
        }
 
        return prefix;
    }
};

int main() {
    Solution s;
    vector<int> nums = {17, 18, 5, 4, 6, 1};
    vector<int> result = s.replaceElements(nums);
    for (auto x : result) {
        cout << x << ",";
    }
}