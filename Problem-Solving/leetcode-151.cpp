// Reverse Words in a string

#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    string trim(string &str) {
        int n = str.size();
        int s = 0;
        int e = n - 1;
        while (str[s] == ' ') s++;
        while (str[e] == ' ') e--;

        string ans;
        for (int st = s; st <= e; st++) {
            ans += str[st];
        }

        return ans;
    }

    string reverseWords(string s) {
        string res = trim(s);
        string ans;
        reverse(res.begin(), res.end());
        int j = 0;
        int i = 0;
        for (; i < res.length(); i++) {
            if (res[i] == ' ') {
                reverse(res.begin() + j, res.begin() + i);
                for(int k = j ;k<i;k++){
                    ans+=res[k];
                }
                ans+=" ";
                int t = i+1;
                while(res[t]==res[i]) t++; 
                j = t;
                i = t-1;
            }
        }
        reverse(res.begin() + j, res.begin() + i);
        for(int k = j ;k<i;k++){
            ans+=res[k];
        }
        return ans;
    }
};


int main() {
    Solution s;
    string str = "the sky is blue";
    cout << s.reverseWords(str) << endl;
}