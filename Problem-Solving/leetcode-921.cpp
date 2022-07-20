// Minimum add to make parentheses valid

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;
        for (auto x : s) {
            if (st.empty()) {
                if (x == '(')
                    st.push(x);
                else
                    count++;
            } else {
                if (x == '(')
                    st.push(x);
                else
                    st.pop();
            }
        }

        while (!st.empty()) {
            count++;
            st.pop();
        }
        return count;
    }
};

int main() {
    Solution s;
    string str = ")(";
    cout << s.minAddToMakeValid(str);
}