//  Remove all duplicates from the string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> currentPresentInStack(26, 0);
        stack<char> st;

        for (int i = 0; s[i] != '\0'; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; s[i] != '\0'; i++) {
            char ch = s[i];
            if (!currentPresentInStack[ch - 'a']) {
                while (!st.empty() and ch < st.top() and
                       lastIndex[st.top() - 'a'] > i) {
                    currentPresentInStack[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(ch);
                currentPresentInStack[ch - 'a'] = 1;
            }
        }

        string output = "";

        while (!st.empty()) {
            output += st.top();
            st.pop();
        }

        reverse(output.begin(), output.end());

        return output;
    }
};

int main() {
    Solution s;
    string str = "priyanshsinghal";
    cout << s.removeDuplicateLetters(str) << endl;
}