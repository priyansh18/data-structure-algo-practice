// Longest K Unique character substring

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestKSubstr(string s, int k) {
        // your code here
        int n = s.length();
        int i = 0;
        int j = 0;
        int maximumLength = -1;
        string output = "";
        unordered_map<char, int> m;
        while (j < n) {
            m[s[j]]++;
            if (m.size() < k) {
                j++;
            } else if (m.size() == k) {
                maximumLength = max(maximumLength, j - i + 1);
                output = s.substr(i, j - i + 1);
                j++;
            } else if (m.size() > k) {
                while (m.size() > k) {
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
        return maximumLength;
    }
};

int main() {
    Solution s;
    string str = "aabacbebebe";
    int k = 3;
    cout << s.longestKSubstr(str, k) << endl;
}