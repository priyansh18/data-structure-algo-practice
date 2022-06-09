// Distribute candies

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int> s;
        for (auto x : candyType) {
            s.insert(x);
        }

        if (s.size() > n / 2) {
            return n / 2;
        }
        return s.size();
    }
};

int main() {
    Solution s;
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    cout << s.distributeCandies(candyType) << endl;
}