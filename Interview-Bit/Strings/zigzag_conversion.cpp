#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1) return s;
        if (numRows > n) return s;
        // Keeps track of direction we are moving in.
        vector<char> r[numRows];
        int delta = -1;
        int row = 0;
        for (auto c : s) {
            r[row].push_back(c);
            if (row == 0 or row == numRows - 1) {
                delta *= -1;
            }

            row += delta;
        }
        string result = "";
        for (auto x : r) {
            for (auto y : x) {
                result += y;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    string str = "PAYPALISHIRING";
    int rows = 4;
    cout << s.convert(str, rows);
}