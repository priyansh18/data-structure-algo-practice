// Number of Ways to Arrive at Destination
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long, long>>> adj(n);
        for (auto x : roads) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        long M = 1e9 + 7;
        vector<long> ways(n, 0);

        priority_queue<pair<long, long>, vector<pair<long, long>>,
                       greater<pair<long, long>>>
            pq;
        vector<long> dist(n, LONG_LONG_MAX);
        vector<long> result;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({dist[0], 0});
        while (!pq.empty()) {
            long wt = pq.top().first;
            long node = pq.top().second;
            pq.pop();

            for (auto nbr : adj[node]) {
                long currWt = nbr.second;
                long currentNode = nbr.first;

                if (wt + currWt < dist[currentNode]) {
                    dist[currentNode] = wt + currWt;
                    ways[currentNode] = ways[node];
                    pq.push({dist[currentNode], currentNode});
                } else if (wt + currWt == dist[currentNode]) {
                    ways[currentNode] = (ways[node] + ways[currentNode]) % M;
                }
            }
        }

        return ways[n - 1];
    }
};

int main() {
    Solution s;
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                                 {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                                 {0, 4, 5}, {4, 6, 2}};
    cout << s.countPaths(n, roads);
}