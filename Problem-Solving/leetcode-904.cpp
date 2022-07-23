// Fruits into Baskets

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int n = fruits.size();
        if (n <= 2) return n;
        int maxFruits = 0;
        map<int, int> m;
        while (j < n) {
            m[fruits[j]]++;
            if (m.size() <= 2) {
                maxFruits = max(maxFruits, j - i + 1);
                j++;
            } else {
                while (m.size() > 2) {
                    m[fruits[i]]--;
                    if (m[fruits[i]] == 0) m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maxFruits;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 2, 2, 2};
    cout << s.totalFruit(nums) << endl;
}