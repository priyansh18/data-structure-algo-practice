// Find All Anagrams in a string

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = p.length();
        int k = s.length();
        int i = 0;
        int j = 0;
        map<char, int> m;
        map<char, int> m1;
        bool flag = true;
        for (auto x : p) {
            m1[x]++;
        }
        while (j < k) {
            m[s[j]]++;
            if (j - i + 1 < n) {
                j++;
            } else {
                for (auto x : m1) {
                    if (m[x.first] != x.second) flag = false;
                }
                if (flag) {
                    result.push_back(i);
                }
                flag = true;
                m[s[i]]--;
                i++;
                j++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    string str = "cbaebabacd";
    string p = "abc";
    vector<int> result = s.findAnagrams(str, p);
    for (auto x : result) cout << x << ",";
}