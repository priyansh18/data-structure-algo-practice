// Valid Palindrome II

class Solution {
   public:
    bool helper(string s, int l, int h, bool count) {
        while (l < h) {
            if (s[l] == s[h]) {
                l++;
                h--;
            } else {
                if (count == true) return false;
                return helper(s, l + 1, h, true) or helper(s, l, h - 1, true);
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length() - 1;
        bool count = false;
        return helper(s, 0, n, count);
    }
};