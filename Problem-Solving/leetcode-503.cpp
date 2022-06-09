// Next Greter Element II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size(); 
        vector<int> res(n);
        
        for(int i = n-1; i>=0; i--){
            while (!st.empty() and nums[st.top()] <= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : nums[st.top()];
            st.push(i);
        }
        
        for(auto x:res){
          cout<<x<<".,";
        }
        cout<<endl;
        for(int i = n-1; i>=0 ;i--){
            while (!st.empty() and nums[st.top()] <= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : nums[st.top()];
            st.push(i);
        }
        
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    vector<int> result = s.nextGreaterElements(nums);
    for (auto x : result) {
        cout << x << ",";
    }
}