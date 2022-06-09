// Remove Palindromic Subssequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removePalindromeSub(string s) {
        string temp = s;
        reverse(s.begin(), s.end());
        return s == temp ? 1 : 2;
    }
};

int main() {
    Solution s;
    string str = "aabbaabababa";
    cout << s.removePalindromeSub(str);
}