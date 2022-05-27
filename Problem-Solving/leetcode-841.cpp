// Keys and rooms

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs_helper(vector<int> graph[], vector<int>& visited, int src) {
        visited[src] = 1;
        for (auto nbr : graph[src]) {
            if (!visited[nbr]) {
                dfs_helper(graph, visited, nbr);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> graph[rooms.size()];
        int i = 0;
        for (auto x : rooms) {
            for (auto c : x) {
                graph[i].push_back(c);
            }
            i++;
        }

        for (int i = 0; i < rooms.size(); i++) {
            cout << " i " << i << ":";
            for (auto x : graph[i]) {
                cout << x << ",";
            }
            cout << endl;
        }

        vector<int> visited(rooms.size(), 0);
        dfs_helper(graph, visited, 0);
        for (auto x : visited) {
            if (x == 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> rooms = {{1}, {}, {0, 3}, {1}};
    cout << s.canVisitAllRooms(rooms);
}