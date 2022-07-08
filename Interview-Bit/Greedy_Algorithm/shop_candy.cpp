#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> candy(int candies[], int N, int k) {
        // Write Your Code here
        vector<int> result;
        sort(candies, candies + N);
        int val = N - k;
        int minimum = 0;
        int maximum = 0;
        for (int i = 0; i < val; i++) {
            minimum += candies[i];
        }
        int j = N - 1;
        while (j >= 0 and val--) {
            maximum += candies[j];
            j--;
        }

        result.push_back(minimum);
        result.push_back(maximum);

        return result;
    }
};

int main() {
    Solution s;
    int N = 4;
    int k = 2;
    int candies[N] = {4, 1, 2, 3};
    vector<int> result = s.candy(candies, N, k);
    for (auto x : result) {
        cout << x << ",";
    }
}