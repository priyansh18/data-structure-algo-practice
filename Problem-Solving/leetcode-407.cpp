// Trapping Rain Water II

#include <bits/stdc++.h>
using namespace std;

struct valPair {
    int val;
    int x;
    int y;

    valPair(int val, int x, int y) {
        this->val = val;
        this->x = x;
        this->y = y;
    }
};

class Compare {
   public:
    bool operator()(valPair A, valPair B) { return A.val > B.val; }
};

class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<valPair, vector<valPair>, Compare> minHeap;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or i == m - 1 or j == 0 or j == n - 1) {
                    minHeap.push(valPair(heightMap[i][j], i, j));
                    visited[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;
        while (!minHeap.empty()) {
            valPair temp = minHeap.top();
            minHeap.pop();
            for (int k = 0; k < 4; k++) {
                int newX = temp.x + directions[k].first;
                int newY = temp.y + directions[k].second;
                if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                    visited[newX][newY] == 0) {
                    ans += max(0, temp.val - heightMap[newX][newY]);
                    minHeap.push(valPair(max(temp.val, heightMap[newX][newY]),
                                         newX, newY));
                    visited[newX][newY] = 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    cout << s.trapRainWater(heightMap);
}
