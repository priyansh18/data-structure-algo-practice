#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    list<pair<int, int>> *l;

    Graph(int v) {
        this->V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int x, int y, int dst) {
        l[x].push_back({dst, y});
        l[y].push_back({dst, x});
    }

    int dijkshtra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        // Setting initial node of source distance as 0.
        dist[src] = 0;

        s.insert({0, src});

        while (!s.empty()) {
            auto it = s.begin();
            int dstTillNow = it->first;
            int vertex = it->second;
            s.erase(it);

            for (auto nbr : l[vertex]) {
                int currentdst = nbr.first;
                int currentVertex = nbr.second;

                if (currentdst + dstTillNow < dist[currentVertex]) {
                    // Remove if nbr already exists inside set
                    auto f = s.find({dist[currentVertex], currentVertex});

                    if (f != s.end()) {
                        s.erase(f);
                    }

                    dist[currentVertex] = currentdst + dstTillNow;
                    s.insert({dist[currentVertex], currentVertex});
                }
            }

        }

        return dist[dest];
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkshtra(0, 4);
}