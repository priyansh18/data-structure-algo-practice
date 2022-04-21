// Min Cost to connect sticks.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumCost(vector<int> &sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto x : sticks) {
            minHeap.push(x);
        }
        int ans = 0;

        while (minHeap.size() > 1) {
            int ele1 = minHeap.top();
            minHeap.pop();
            int ele2 = minHeap.top();
            minHeap.pop();
            ans += ele1 + ele2;
            minHeap.push(ele1 + ele2);
        }

        return ans;
    }
};
int main() {
    Solution s;
    vector<int> sticks = {1,8,3,5};
    cout << s.minimumCost(sticks) << endl;
}