// Backspace string compare

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string preprocessingString(string &s) {
        string ans = "";
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] != '#') {
                st.push(s[i]);
            } else {
              if(!st.empty()){

                st.pop();
              }
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        string l = preprocessingString(s);
        string m = preprocessingString(t);
        return l == m;
    }
};

int main() {
    Solution a;
    string s = "y#fo##f";
    string t = "y#f#o##f";
    cout << a.backspaceCompare(s, t) << endl;
}