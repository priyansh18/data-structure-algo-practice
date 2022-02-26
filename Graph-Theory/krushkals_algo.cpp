#include <bits/stdc++.h>
using namespace std;

class DSU {
    int *parent;
    int *rank;

   public:
    //  Constructor
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = -1;
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
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

struct Graph {
    vector<vector<int>> edgelist;
    int V;

    Graph(int v) { this->V = v; }

    void addEdge(int x, int y, int wt) { edgelist.push_back({wt, x, y}); }

    int krushkal_mst() {
        // Sort all the edges based on weight
        sort(edgelist.begin(), edgelist.end());
        int ans = 0;

        DSU s(V);

        for (auto edge : edgelist) {
            int wt = edge[0];
            int x = edge[1];
            int y = edge[2];

            int s1 = s.findSet(x);
            int s2 = s.findSet(y);

            if (s1 != s2) {
                s.union_set(s1, s2);
                ans += wt;
            }
        }

        return ans;
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 12);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 5, 10);
    g.addEdge(3, 6, 8);
    g.addEdge(3, 7, 5);
    g.addEdge(4, 5, 3);
    g.addEdge(5, 7, 6);
    g.addEdge(6, 7, 9);
    g.addEdge(6, 8, 2);
    g.addEdge(7, 8, 11);

    cout << g.krushkal_mst() << endl;
}