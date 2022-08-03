// The Maze

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

    bool hasPath(vector<vector<int>> &maze, vector<int> &start,
                 vector<int> &destination) {
        // write your code here
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[start[0]][start[1]] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (x == destination[0] and y == destination[1]) return true;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int newX = x;
                int newY = y;
                while (newX >= 0 and newX < m and newY >= 0 and newY < n and
                       maze[newX][newY] == 0) {
                    newX += dx[k];
                    newY += dy[k];
                }
                newX -= dx[k];
                newY -= dy[k];
                if (visited[newX][newY] == 0) {
                    visited[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }

        return false;
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
    vector<int> destination = {3, 2};
    cout << s.hasPath(grid, start, destination);
}