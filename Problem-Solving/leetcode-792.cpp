// Number of matching subsequences

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; s[i] != '\0'; i++) {
            m[s[i]].push_back(i);
        }
        int count = 0;
        for (auto x : words) {
            int idx = -1;
            for (int i = 0; i < x.length(); i++) {
                auto it = upper_bound(m[x[i]].begin(), m[x[i]].end(), idx);
                if (it == m[x[i]].end()) break;
                idx = *it;
                if (i == x.length() - 1) count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    string str = "dsahjpjauf";
    vector<string> words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    cout << s.numMatchingSubseq(str, words);
}