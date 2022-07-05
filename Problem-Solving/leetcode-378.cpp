// Kth smallest element in sorted matrix

#include <bits/stdc++.h>
using namespace std;

class valPair {
   public:
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
    // Time Complexity - O(nlogk) and Space Complexity - O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }

    // Optimized Approach
    int kthSmallestOpt(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s = matrix[0][0];
        int e = matrix[m - 1][n - 1];

        while (s < e) {
            int mid = (s + e) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                         matrix[i].begin();
            }

            if (count < k) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s;
    }

    class valPair {
       public:
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
        int kthSmallestOptimize(vector<vector<int>>& matrix, int k) {
            int n = matrix.size();
            vector<vector<int>> visited(n, vector<int>(n, 0));
            priority_queue<valPair, vector<valPair>, Compare> pq;
            pq.push({matrix[0][0], 0, 0});
            visited[0][0] = 1;
            int count = 0;
            while (!pq.empty()) {
                auto temp = pq.top();
                count++;
                if (count == k) {
                    return pq.top().val;
                }
                pq.pop();
                if (temp.y < n and temp.x + 1 < n and
                    !visited[temp.x + 1][temp.y]) {
                    visited[temp.x + 1][temp.y] = 1;
                    pq.push({matrix[temp.x + 1][temp.y], temp.x + 1, temp.y});
                }
                if (temp.x < n and temp.y + 1 < n and
                    !visited[temp.x][temp.y + 1]) {
                    visited[temp.x][temp.y + 1] = 1;
                    pq.push({matrix[temp.x][temp.y + 1], temp.x, temp.y + 1});
                }
            }

            return -1;
        }
    };
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << s.kthSmallest(matrix, k);
    cout << s.kthSmallestOpt(matrix, k);
    cout << s.kthSmallestOptimize(matrix, k);
}