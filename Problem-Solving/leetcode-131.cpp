// Palindrome Partitioning

class Solution {
   public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    vector<vector<string>> helper(int idx, string &str) {
        if (idx == str.size()) return {{}};
        vector<vector<string>> result;

        for (int i = idx; i < str.size(); i++) {
            string x = str.substr(idx, i - idx + 1);

            if (isPalindrome(x)) {
                vector<vector<string>> a = helper(i + 1, str);
                for (auto c : a) {
                    vector<string> k;
                    k.push_back(x);
                    for (auto m : c) {
                        k.push_back(m);
                    }
                    result.push_back(k);
                }
            }
        }

        return result;
    }
    vector<vector<string>> partition(string s) { return helper(0, s); }
};