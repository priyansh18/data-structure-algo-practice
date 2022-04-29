// First Unique Character in a string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < s.length(); i++) {
            if (m1.count(s[i]) == 0) {
                m2[s[i]] = i;
            }
            m1[s[i]]++;
        }

        int minIndex = INT_MAX;
        for (auto x : m1) {
            for (auto c : m2) {
                if (x.second == 1 and x.first == c.first) {
                    minIndex = min(c.second, minIndex);
                }
            }
        }

        return minIndex == INT_MAX ? -1 : minIndex;
    }
};

int main() {
    Solution s;
    // string str = "priyanshsinghal";
    string str = "loveleetcode";
    cout << s.firstUniqChar(str);
}