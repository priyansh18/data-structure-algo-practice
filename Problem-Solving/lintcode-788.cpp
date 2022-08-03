//  The Maze II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    struct ValPair {
        int wt;
        int x;
        int y;

        ValPair(int _wt, int _x, int _y) {
            wt = _wt;
            x = _x;
            y = _y;
        }
    };

    class Compare {
      public:
        bool operator()(ValPair A, ValPair B) { return A.wt > B.wt; }
    };

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                         vector<int> &destination) {
        // write your code here
        int m = maze.size();
        int n = maze[0].size();
        priority_queue<ValPair, vector<ValPair>, Compare> pq;
        vector<int> dist(m * n + 1, INT_MAX);
        dist[start[0] * n + start[1]] = 0;
        pq.push({0, start[0], start[1]});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            int wt = pq.top().wt;
            int x = pq.top().x;
            int y = pq.top().y;
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int newX = x;
                int newY = y;
                int count = 0;
                while (newX >= 0 and newX < m and newY >= 0 and newY < n and
                       maze[newX][newY] == 0) {
                    newX += dx[k];
                    newY += dy[k];
                    count++;
                }
                newX -= dx[k];
                newY -= dy[k];
                count--;
                if (wt + count < dist[newX * n + newY]) {
                    dist[newX * n + newY] = wt + count;
                    pq.push({wt + count, newX, newY});
                }
            }
        }

        if (dist[destination[0] * n + destination[1]] == INT_MAX) {
            return -1;
        } else {
            return dist[destination[0] * n + destination[1]];
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {1, 1, 0, 1, 1},
                                {0, 0, 0, 0, 0}};
    vector<int> start = {0, 4};
    vector<int> destination = {0, 0};
    cout << s.shortestDistance(grid, start, destination);
}