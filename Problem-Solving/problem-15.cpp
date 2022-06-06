// Book Store

#include <bits/stdc++.h>
using namespace std;

int getLeftVal(vector<int> &nums, int i){
  i--;
  while(i>=0){
    if(nums[i] >= 0) return nums[i];
    i--;
  }

  return 1;
}

int getRightVal(vector<int> &nums, int i){
  i++;
  while(i<nums.size()){
    if(nums[i] >= 0) return nums[i];
    i++;
  }
  return 1;
}

int maximumCost(vector<int>& nums, int taken = 0) {
    int n = nums.size();
    if (taken == n){
      return 0;
    }

    int maxx = 0;
    for (int i = 0; i < n; i++) {
      if(nums[i] < 0) continue;
      int temp = nums[i]*(getLeftVal(nums, i))*(getRightVal(nums, i));
      nums[i] = -nums[i];
      int subMax = maximumCost(nums, taken+1);
      maxx = max(maxx, temp + subMax);
      nums[i] = -nums[i];
    }

    return maxx;
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << maximumCost(nums);
}