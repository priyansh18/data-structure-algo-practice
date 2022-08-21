// Maximum sum of all distinct element in window of size k;

#include <bits/stdc++.h>
using namespace std;

int maxSumK(vector<int> nums, int k) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int maxSum = -1;
    int sum = 0;
    map<int, int> m;
    int count = 0;
    while (j < n) {
        if (m.count(nums[j]) == 0) count++;
        m[nums[j]]++;
        sum += nums[j];
        if (j - i + 1 < k) {
            j++;
        } else {
            if (count == k) {
                maxSum = max(maxSum, sum);
            }
            m[nums[i]]--;
            if (m[nums[i]] == 0) count--;
            sum -= nums[i];
            i++;
            j++;
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 3, 2, 1};
    vector<int> nums2 = {1, 2, 2};
    int k = 3;
    cout << maxSumK(nums, k) << endl;
    cout << maxSumK(nums2, k);
}