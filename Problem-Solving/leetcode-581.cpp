// Shortest Unsorted Continuous Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //    O(n^2 Approach)
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = nums.size();
        int end = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    start = min(start, i);
                    end = max(end, j);
                }
            }
        }

        cout << end << " and " << start << endl;

        if ((end - 1) < 0) {
            return 0;
        } else {
            return end - start + 1;
        }
    }

    //    O(nlogn Approach)
    int findUnsortedSubarray2(vector<int>& nums) {
        int n = nums.size();
        int start = nums.size();
        int end = 0;

        vector<int> snums;
        snums = nums;
        sort(snums.begin(), snums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != snums[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }

        cout << end << " and " << start << endl;

        if ((end - 1) < 0) {
            return 0;
        } else {
            return end - start + 1;
        }
    }

    // O(n) Approach
    int findUnsortedSubarray3(vector<int>& nums) {
        int n = nums.size();
        int smallest = 0;
        int largest = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) {
                smallest = i;
            }
        }

        for (int j = n - 2; j >= 1; j--) {
            if (nums[j] < nums[j + 1] and nums[j] < nums[j - 1]) {
                largest = j + 1;
            }
        }

        cout << largest << " and " << smallest << endl;

        if (smallest - 1 < 0) {
            return 0;
        } else {
            return largest - smallest + 1;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    cout << s.findUnsortedSubarray(nums);
    cout << endl;
    cout << s.findUnsortedSubarray2(nums);
    cout << endl;
    cout << s.findUnsortedSubarray3(nums);
    return 0;
}