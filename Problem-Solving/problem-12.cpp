// Rearrange Characters to form a palindrome.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canStringBePalindrome(string str) {
        map<char, int> m;

        for (int i = 0; i < str.length(); i++) {
            m[str[i]]++;
        }

        int count = 0;

        for (auto x : m) {
            if ((x.second) % 2 != 0) {
                count++;
            }
        }

        cout << count << endl;

        return count > 1 ? false : true;
    }
};

int main(){
    Solution s;
    string str = "lelle";
    cout << s.canStringBePalindrome(str) << endl;
}