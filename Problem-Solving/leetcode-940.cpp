// Distinct Subsequences II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void helper(string s, int i, int j, string output, vector<string> &result) {
        if (i > j) {
            if(output=="")
            result.push_back(output);
            return;
        }

        helper(s, i + 1, j, output + s[i], result);

        helper(s, i + 1, j, output, result);
    }

    int distinctSubseqII(string s) {
        vector<string> result;
        set<string> st;
        string output = "";
        int n = s.length();
        helper(s, 0, n - 1, output, result);
        for (auto x : result) {
            st.insert(x);
        }

        return st.size();
    }
};

int main() {
    Solution p;
    string s = "abc";
    cout << p.distinctSubseqII(s);
}