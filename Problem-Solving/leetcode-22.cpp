// Generate Paranthesis

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void generateParenthesisHelper(vector<string> &result, string output,
                                   int open, int close, int n) {
        if (output.size() == 2 * n) {
            result.push_back(output);
            return;
        }

        if (open < n) {
            generateParenthesisHelper(result, output + "(", open + 1, close, n);
        }

        if (close < open) {
            generateParenthesisHelper(result, output + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string output = "(";
        generateParenthesisHelper(result, output, 1, 0, n);
        return result;
    }
};

int main() {
    Solution s;
    int n = 4;
    vector<string> result = s.generateParenthesis(n);

    for (auto x : result) {
        cout << x << ",";
    }
}