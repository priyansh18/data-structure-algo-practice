// Longest Substring without repeating character.

#include <bits/stdc++.h>
using namespace std;

// class Solution {
//    public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         map<char, int> m;
//         int i = 0;
//         int j = 0;
//         int ans = 0;
//         while (i < n) {
//             if (m.count(s[i]) != 0) {
//                 // J is taken as max because j should not be shifted
//                 backwards. j = max(j, m[s[i]] + 1); m[s[i]] = i;
//             } else {
//                 m[s[i]] = i;
//             }
//             ans = max(ans, i - j + 1);
//             i++;
//         }

//         return ans;
//     }
// };

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxL = 0;
        string output = "";
        map<char, int> m;
        while (j < n) {
            m[s[j]]++;
            if (m.size() == j - i + 1) {
                maxL = max(maxL, j - i + 1);
                output = s.substr(i, j - i + 1);
                j++;
            } else if (m.size() < j - i + 1) {
                while (m.size() < j - i + 1) {
                    m[s[i]]--;
                    if (m[s[i]] == 0) {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        cout << output << endl;
        return maxL;
    }
};

int main() {
    Solution s;
    string str = "pwwkew";
    cout << s.lengthOfLongestSubstring(str);
}