// Remove K digits

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) return "0";

        stack<char> st;

        for (char c : num) {
            while (k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k-- > 0) st.pop();

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        auto idx = res.length() - 1;
        for (int i = 0; i < res.length(); i++) {
            if (res[i] == '0') continue;
            idx = i;
            break;
        }
        res = res.substr(idx);

        return res;
    }
};

int main() {
    Solution s;
    string num = "10200";
    int k = 1;
    cout << s.removeKdigits(num, k);
}