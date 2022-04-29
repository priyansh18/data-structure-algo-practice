// Remove all adjacent duplicates in a string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (s[i] == st.top()) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution s;
    string str = "axzzxy";
    cout << s.removeDuplicates(str) << endl;
}