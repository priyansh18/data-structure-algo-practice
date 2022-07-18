#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if (n == 0) return 0;
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    string str = "hello";
    string p = "ll";
    cout << s.strStr(str, p);
}