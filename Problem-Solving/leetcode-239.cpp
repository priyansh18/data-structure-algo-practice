// Maximum of all subarray of size k
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        if (k > n) {
            result.push_back(*max_element(nums.begin(), nums.end()));
            return result;
        }
        int i = 0;
        int j = 0;
        deque<int> q;
        while (j < n) {
            // Removing all smaller element than current
            while (!q.empty() and q.back() < nums[j]) {
                q.pop_back();
            }
            q.push_back(nums[j]);
            if (j - i + 1 < k) {
                j++;
            } else {
                result.push_back(q.front());
                if (q.front() == nums[i]) {
                    q.pop_front();
                }
                i++;
                j++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 7, 8, 11};
    int k = 2;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for (auto x : result) cout << x << ",";
}