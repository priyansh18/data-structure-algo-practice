// Check if the parentheses are balanced or not

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == '{' or s[i] == '[' or s[i] == '(') {
            st.push(s[i]);
        }
        if (s[i] == '}' or s[i] == ']' or s[i] == ')') {
            if (st.empty()) {
                return false;
            } else {
                char temp = st.top();
                if (s[i] == '}' and temp == '{') {
                    st.pop();
                } else if (s[i] == ')' and temp == '(') {
                    st.pop();
                } else if (s[i] == ']' and temp == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
    }

    if (st.empty()) {
        return true;
    }

    return false;
}

int main() {
    stack<char> s;
    sing s = "({}})";
    cout << isBalanced(s) << endl;
}