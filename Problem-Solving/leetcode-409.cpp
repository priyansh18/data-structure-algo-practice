class Solution {
   public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (auto x : s) {
            m[x]++;
        }

        int length = 0;
        bool flag = false;
        for (auto x : m) {
            if (x.second % 2 == 0) {
                length += x.second;
            } else {
                flag = true;
                length += (x.second / 2) * 2;
            }
        }
        if (flag) return length + 1;
        return length;
    }
};