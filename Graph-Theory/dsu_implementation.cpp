#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    list<pair<int, int> > l;

    Graph(int v) { this->V = v; }

    void addEdge(int u, int v) { l.push_back({u, v}); }

    // Disjoint Set Operations

    // Find

    int findSet(int i, vector<int> &parent) {
        if (parent[i] == -1) {
            return i;
        }

        return parent[i] = findSet(parent[i], parent);
    }

    // Union

    void union_set(int a, int b, vector<int> &parent, vector<int> &rank) {
        int s1 = findSet(a, parent);
        int s2 = findSet(b, parent);

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

    bool contains_cycle() {
        // DSU logic to check if graph contains cycle or not
        vector<int> parent(V, -1);
        vector<int> rank(V, 1);

        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2) {
                union_set(s1, s2, parent, rank);
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.addEdge(3, 0);
    cout << g.contains_cycle() << endl;
}