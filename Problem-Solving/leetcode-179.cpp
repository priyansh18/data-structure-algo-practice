// Largest Number

#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(string s1, string s2) { return (s1 + s2) > (s2 + s1); }
};

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        vector<string> st;
        int count=0;
        for (auto x : nums) {
            if(x==0) count++;
            st.push_back(to_string(x));
        }
        if(count==n) return "0";
        sort(st.begin(), st.end(), Compare());

        string output = "";

        for (auto x : st) {
            output += x;
        }

        return output;
    }
};u

int main() {
    Solution s;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << s.largestNumber(nums);
}