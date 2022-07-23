// Smallest Window Containing all the characters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        // Base Conditions
        int p = s.length();
        int n = t.length();

        if (n > p) return "";
        if (s == t) return s;

        unordered_map<char, int> m;

        for (auto x : t) {
            m[x]++;
        }

        string output = "";
        int count = m.size();
        int i = 0;
        int j = 0;
        int minWindowSize = INT_MAX;

        while (j < p) {
            if (m.find(s[j]) != m.end()) {
                m[s[j]]--;
                if (m[s[j]] == 0) count--;
            }

            if (count == 0) {
                if (j - i + 1 < minWindowSize) {
                    output = s.substr(i, j - i + 1);
                    minWindowSize = j - i + 1;
                }

                while (count == 0) {
                    if (m.find(s[i]) != m.end()) {
                        if (m[s[i]] == 0 || m[s[i]] < 0) {
                            m[s[i]]++;
                            if (m[s[i]] > 0) count++;
                        }
                    }
                    i++;
                    if (j - i + 1 < minWindowSize && count == 0) {
                        output = s.substr(i, j - i + 1);
                        minWindowSize = j - i + 1;
                    }
                }
            }

            j++;
        }

        return output;
    }
};

int main() {
    Solution a;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << a.minWindow(s, t);
}