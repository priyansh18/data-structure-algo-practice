#include <iostream>
#include <list>
#include <set>
#include <vector>
#include<climits>
using namespace std;

class Node {
   public:
    int x;
    int y;
    int dist;

    Node(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

class Compare {
   public:
    bool operator()(const Node &a, const Node &b) { return a.dist < b.dist; }
};

int shortest_path(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = 0;
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX));
    set<Node, Compare> s;
    dist[i][j] = grid[0][0];

    s.insert(Node(0, 0, dist[0][0]));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!s.empty()) {
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cdist = it->dist;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx >= 0 and ny >= 0 and nx < m and ny < n and
                cdist + grid[nx][ny] < dist[nx][ny]) {
                Node temp(nx, ny, dist[nx][ny]);
                if (s.find(temp) != s.end()) {
                    s.erase(s.find(temp));
                }
                int ndist = grid[nx][ny] + cdist;
                dist[nx][ny] = ndist;
                s.insert(Node(nx, ny, ndist));
            }
        }
    }

    return dist[m - 1][n - 1];
}

int main() {


    vector<vector<int>> grid = {{31, 100, 65, 12, 18},
                                {10, 13, 47, 157, 6},
                                {100, 113, 174, 11, 33},
                                {88, 124, 41, 20, 140},
                                {99, 32, 111, 41, 20}};

    cout << shortest_path(grid) << endl;
}