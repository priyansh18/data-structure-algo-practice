// Longest Substring without repeating character.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> m;
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < n) {
            if (m.count(s[i]) != 0) {
                // J is taken as max because j should not be shifted backwards.
                j = max(j, m[s[i]] + 1);
                m[s[i]] = i;
            } else {
                m[s[i]] = i;
            }
            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;
    }
};

int main() {
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str);
}