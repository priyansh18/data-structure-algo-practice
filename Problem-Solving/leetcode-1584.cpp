// Min cost to connect all points

#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    int *parent;
    int *rank;

    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = rank[i] = -1;
        }
    }

    int findSet(int i) {
        if (parent[i] == -1) {
            return i;
        }

        return parent[i] = findSet(parent[i]);
    }

    void union_set(int a, int b) {
        int s1 = findSet(a);
        int s2 = findSet(b);

        if (s1 != s2) {
            if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            } else {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};

struct Graph {
    vector<vector<int>> edgelist;
    int V;

    Graph(int v) { V = v; }

    void addEdge(int wt, int x, int y) { edgelist.push_back({wt, x, y}); }

    void printList() {
        for (auto x : edgelist) {
            cout << x[0] << " and " << x[1] << " and " << x[2] << endl;
        }
    }

    int krushkal() {
        DSU s(V);
        // Using Sorting Exceeds time limit
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            p(edgelist.begin(), edgelist.end());
        int ans = 0;
        int cnt = 0;

        while (cnt < V-1) {
            auto front = p.top();
            p.pop();
            int dist = front[0];
            int a = front[1];
            int b = front[2];

            int s1 = s.findSet(a);
            int s2 = s.findSet(b);

            if (s1 != s2) {
                s.union_set(s1, s2);
                ans += dist;
                cnt++;
            }
        }

        return ans;
    }
};

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        map<int, pair<int, int>> m;
        for (int i = 0; i < points.size(); i++) {
            m[i] = {points[i][0], points[i][1]};
        }

        Graph g(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                g.addEdge(abs(points[i][0] - points[j][0]) +
                              abs(points[i][1] - points[j][1]),
                          i, j);
            }
        }

        g.printList();

        return g.krushkal();
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << s.minCostConnectPoints(points);
}