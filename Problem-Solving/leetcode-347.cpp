// Top K Frequent Elements.

#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            // To check based on nums
            return p1.second > p2.second;
        }
        // Based on Value
        return p1.first < p2.first;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> m;
        // Initialize the map with frequency.
        for (auto x : nums) {
            m[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;

        for(auto x: m){
            maxHeap.push({x.second,x.first});
        }

        while (k--) {
            auto res = maxHeap.top();
            maxHeap.pop();
            result.push_back(res.second);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> result = s.topKFrequent(nums, 2);
    for (auto x : result) {
        cout << x << ",";
    }
    return 0;
}