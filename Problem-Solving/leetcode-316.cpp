//  Remove all duplicates from the string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if (n == 0) return "";
        vector<int> counter(26, 0);

        for (char& c : s) {
            ++counter[c - 'a'];
        }

        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] < s[start]) {
                start = i;
            }
            --counter[s[i] - 'a'];
            // there are counter[s[i]-'a'] s[i] in s[i+1...]
            if (counter[s[i] - 'a'] == 0) {
                // skip those index s.t. s[i] is missing
                break;
            }
        }

        string nexts = s.substr(start + 1);
        auto it = remove(nexts.begin(), nexts.end(), s[start]);
        nexts = std::string(nexts.begin(), it);
        // cout << "remove " << s[start] << ", next: " << nexts << endl;
        return s[start] + removeDuplicateLetters(nexts);
    }
};

int main() {
    Solution s;
    string str = "priyanshsinghal";
    cout << s.removeDuplicateLetters(str) << endl;
}