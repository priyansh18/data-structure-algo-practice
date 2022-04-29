// Smallest Window Containing all the characters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        string ans = "";
        int m = s.size();
        int n = t.size();

        map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int matchCount = 0;
        int desiredMatchCount = n;

        map<char, int> ms;

        int i = -1;
        int j = -1;

        while (true) {
            bool f1 = false;
            bool f2 = false;
            // Acquire
            while (i < m - 1 && matchCount < desiredMatchCount) {
                i++;
                ms[s[i]]++;

                if (ms[s[i]] <= mp[s[i]]) {
                    matchCount++;
                }
                f1 = true;
            }

            // Collect answers & release.
            while (j < i && matchCount == desiredMatchCount) {
                string CanBeAnAnswer = s.substr(j + 1, i + 1);
                if (ans.length() == 0 ||
                    CanBeAnAnswer.length() < ans.length()) {
                    ans = CanBeAnAnswer;
                }

                j++;
                if (ms[s[i]] == 1) {
                    ms.erase(s[i]);
                } else {
                    ms[s[i]]--;
                }

                if (ms[s[i]] < mp[s[i]]) {
                    matchCount--;
                }

                f2 = true;
            }

            if (f1 == false && f2 == false) {
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution a;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << a.minWindow(s, t);
}