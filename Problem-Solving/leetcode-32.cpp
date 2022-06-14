// Longest Valid Parenthesis

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string str) {
        int n = str.length();
        int i = 0;
        stack<int> s;
        int count = 0;
        int maxVal = 0;
        while (i < n) {
            if (str[i] == '(') {
                s.push(count);
                count = 0;
            } else {
                if (s.empty()) {
                    // Invalid Parenthesis
                    count = 0;
                } else {
                    count = count + s.top() + 2;
                    s.pop();
                    maxVal = max(count, maxVal);
                }
            }
            i++;
        }

        return maxVal;
    }
};

int main() {
    Solution s;
    string str = "())(())";
    cout << s.longestValidParentheses(str) << endl;
}