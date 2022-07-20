// Binary Gap

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string convertToBinary(int n) {
        string ans = "";
        while (n != 0) {
            ans += to_string(n % 2);
            n = n / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int binaryGap(int n) {
        string binary = convertToBinary(n);
        int dist = 0;
        int lastIndex = -1;
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '1') {
                if (lastIndex == -1) {
                    lastIndex = i;
                    continue;
                }
                if (i - lastIndex >= dist) {
                    dist = i - lastIndex;
                }
                lastIndex = i;
            }
        }
        return dist;
    }
};

int main() {
    Solution s;
    int n = 22;
    cout << s.binaryGap(n) << endl;
}