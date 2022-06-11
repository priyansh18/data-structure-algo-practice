// Minimum Knight Moves.

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int knight(int A, int B, int c, int d, int e, int f) {
        int C = c - 1;
        int D = d - 1;
        int E = e - 1;
        int F = f - 1;
        queue<pair<int, int>> q;

        vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

        vector<vector<int>> visited(A, vector<int>(B, 0));
        q.push({C, D});
        visited[C][D] = 1;
        q.push({-1, -1});
        int level = 0;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp.first == -1 and temp.second == -1) {
                level++;
                if (!q.empty()) q.push({-1, -1});
            } else {
                if (temp.first == E and temp.second == F) return level;
                for (int k = 0; k < 8; k++) {
                    int newDx = temp.first + dx[k];
                    int newDy = temp.second + dy[k];

                    if (newDx >= 0 and newDx < A and newDy >= 0 and
                        newDy < B and !visited[newDx][newDy]) {
                        visited[newDx][newDy] = 1;
                        q.push({newDx, newDy});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.knight(8, 8, 1, 1, 8, 8) << endl;
}