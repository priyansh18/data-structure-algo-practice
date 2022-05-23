// Letter Combination of a phone number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> mappingDigits = {"abc", "def",  "ghi", "jkl",
                                    "mno", "pqrs", "tuv", "wxyz"};

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) {
            return result;
        }
        
        if (digits.length() == 1) {
            int idx = (int)digits[0] - 48;
            for (char x : mappingDigits[idx - 2]) {
                string temp = "";
                temp += x;
                result.push_back(temp);
            }
            return result;
        }

        vector<string> subResult = letterCombinations(digits.substr(1));

        int idx = (int)digits[0] - 48;
        for (auto x : mappingDigits[idx - 2]) {
            for (auto y : subResult) {
                string temp = "";
                temp += x;
                temp += y;
                result.push_back(temp);
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    string str = "23439284932";
    vector<string> result = s.letterCombinations(str);
    for (auto x : result) {
        cout << x << ",";
    }
}