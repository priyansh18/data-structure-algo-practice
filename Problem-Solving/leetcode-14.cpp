// Longest Common Prefix.

#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            int k = 0;
            string newStr = strs[i];
            while (k < newStr.length() and result[k] == newStr[k]) {
                k++;
            }
            result = result.substr(0, k);
        }

        return result.length() == 0 ? "" : result;
    }

};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flie"};
    cout << s.longestCommonPrefix(strs) << endl;
}