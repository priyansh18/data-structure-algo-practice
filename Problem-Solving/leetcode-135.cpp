// Candy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                left2right[i] = left2right[i-1]+1;
            }
        }
        
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                right2left[i] = right2left[i+1]+1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            ans += max(left2right[i], right2left[i]);
        }
        
        return ans;
    }
};

#define pii pair<int, int>

class Compare {
   public:
    bool operator()(pii A, pii B) {
        if (A.first == B.first) {
            return A.second < B.second;
        }
        return A.first > B.first;
    }
};

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> givenCandy(n, 0);
        priority_queue<pii, vector<pii>, Compare> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push({ratings[i], i});
        }

        int ans = 0;

        while (!minHeap.empty()) {
            auto temp = minHeap.top();
            minHeap.pop();

            if (temp.second == 0) {
                if (givenCandy[temp.second + 1]) {
                    int newVal = givenCandy[temp.second + 1] + 1;
                    givenCandy[temp.second] = newVal;
                } else {
                    givenCandy[temp.second] = 1;
                }
            }

            else if (temp.second == n - 1) {
                if (givenCandy[temp.second - 1]) {
                    int newVal = givenCandy[temp.second - 1] + 1;
                    givenCandy[temp.second] = newVal;
                } else {
                    givenCandy[temp.second] = 1;
                }
            }

            else {
                if (givenCandy[temp.second + 1] or
                    givenCandy[temp.second - 1]) {
                    int newVal = max(givenCandy[temp.second + 1],
                                     givenCandy[temp.second - 1]) +
                                 1;
                    givenCandy[temp.second] = newVal;
                } else {
                    givenCandy[temp.second] = 1;
                }
            }
        }

        for (auto x : givenCandy) {
            ans += x;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ratings = {1,2,2};
    cout << s.candy(ratings);
}