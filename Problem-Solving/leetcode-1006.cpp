// Clumsy Factorial

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int clumsy(int n) {
        int ans = 0;
        bool firstTime = true;
        while (n) {
            int temp = n--;
            if (n >= 1) temp *= n--;
            if (n >= 1) temp /= n--;
            if (firstTime) {
                if (n >= 1) temp += n--;
                ans += temp;
                firstTime = false;
            } else {
                if (n >= 1) temp -= n--;
                ans -= temp;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.clumsy(n) << endl;
}