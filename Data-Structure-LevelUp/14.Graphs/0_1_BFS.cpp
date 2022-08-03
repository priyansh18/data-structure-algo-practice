#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 3, 0},
                                 {3, 2, 1}, {2, 4, 0}, {2, 5, 0}};
    for (auto x : edges) {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    deque<pair<int, int>> q;
    q.push_back({0, 0});

    while (!q.empty()) {
        int node = q.front().first;
        int weight = q.front().second;
        q.pop_front();

        for (auto nbr : adj[node]) {
            int currNode = nbr.first;
            int currWeight = nbr.second;

            if (weight + currWeight < dist[currNode]) {
                dist[currNode] = weight + currWeight;
                if (currWeight == 1) {
                    q.push_back({currNode, dist[currNode]});
                } else {
                    q.push_front({currNode, dist[currNode]});
                }
            }
        }
    }

    for (auto x : dist) {
        cout << x << ",";
    }

    return 0;
}