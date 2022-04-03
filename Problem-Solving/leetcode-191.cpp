// Find Number of 1 bits

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void hammingWeightShort(uint32_t n) {
        cout << "Number of 1's : " << __builtin_popcount(n) << endl;
        cout << "Number of Trailing Zeroes : " << __builtin_ctz(n) << endl;
        cout << "Number of Leading Zeroes : " << __builtin_clz(n) << endl;
    }

    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n & 1) count++;
            n = n >> 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    int n = 0b00000000000000000000000000001011;
    cout << s.hammingWeight(n) << endl;
    int m = 0b11111111111111111111111111111101;
    cout << s.hammingWeight(m) << endl;

    s.hammingWeightShort(n);
    cout << endl;
    s.hammingWeightShort(m);
    cout << endl;
}