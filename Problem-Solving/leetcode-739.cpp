// Daily Temperature

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result;
        stack<int> s;
        int i = n - 1;
        while (i >= 0) {
            if (s.empty()) {
                result.push_back(0);
            } else {
                if (temperatures[i] >= temperatures[s.top()]) {
                    while (!s.empty() and
                           temperatures[i] >= temperatures[s.top()]) {
                        s.pop();
                    }
                    if (s.empty())
                        result.push_back(0);
                    else
                        result.push_back(s.top() - i);

                } else {
                    result.push_back(s.top() - i);
                }
            }
            s.push(i);
            i--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = s.dailyTemperatures(temperatures);
    for (auto x : result) {
        cout << x << ",";
    }
}