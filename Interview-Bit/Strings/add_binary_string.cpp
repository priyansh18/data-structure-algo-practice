#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        string res;
        int i = 0;
        int m = a.length();
        int n = b.length();
        int sum = 0;
        int carry = 0;
        while (i >= 0 or j >= 0 or carry != 0) {
            sum = carry;
            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';
            res += to_string(sum % 2);
            carry = sum / 2;
            i--;
            j--;
        }

        if (carry) {
            res += to_string(carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {}