// String Compression

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        vector<char> st;
        int i = 0;
        int j = 0;

        while (i < chars.size()) {
            while (i<chars.size() and chars[i] == chars[j]) {
                i++;
            }
            if (i - j > 1) {
                st.push_back(chars[j]);
                string str = to_string(i - j);
                for (int k = 0; k < str.size(); k++) {
                    st.push_back(str[k]);
                }
            } else {
                st.push_back(chars[j]);
            }

            j = i;
        }

        chars.clear();

        for (auto x : st) {
            cout << x << ",";
            chars.push_back(x);
        }

        return chars.size();
    }
};

int main() {
    Solution s;
    vector<char> ch = {'a', 'a'};
    cout << s.compress(ch) << endl;
}