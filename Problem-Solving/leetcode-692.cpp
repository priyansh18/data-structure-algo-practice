// Top K Frequent Words.

#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(pair<int, string> p1, pair<int, string> p2) {
        if (p1.first == p2.first) {
            // To check based on words
            return p1.second > p2.second;
        }
        // Based on Value
        return p1.first < p2.first;
    }
};

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        map<string, int> m;
        // Initialize the map with frequency.
        for (auto x : words) {
            m[x]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> maxHeap;

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
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> result = s.topKFrequent(words, 2);
    for (auto x : result) {
        cout << x << ",";
    }
    return 0;
}