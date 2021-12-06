#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    list<pair<int, int>> *l;

   public:
    Graph(int v) {
        this->vertices = v;
        l = new list<pair<int, int>>[v];
    }

    void addEdgeDj(int i, int j, int wt, bool undir = true) {
        l[i].push_back({wt, j});
        if (undir) {
            l[j].push_back({wt, i});
        }
    }

    // Dijkshtra's Algorithm
    int dijkshtra(int src, int dest) {
        // Visited Array
        vector<int> dist(vertices, INT8_MAX);
        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int nodeDist = it->first;

            s.erase(it);
            // Iterate over the neighbours of node.
            for (auto nbrs : l[node]) {
                int nbr = nbrs.second;
                int currentEdge = nbrs.first;

                if (nodeDist + currentEdge < dist[nbr]) {
                    // Removing the element if already  present in set
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    // Insert the updated value with new distance

                    dist[nbr] = nodeDist + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // Single Source Shortest to all other nodes.
        for (int i = 0; i < vertices; i++) {
            cout << "Node " << i << " Dist "
                 << " " << dist[i] << endl;
        }

        return dist[dest];
    }
};

int main() {
    Graph i(5);
    i.addEdgeDj(0, 1, 1);
    i.addEdgeDj(1, 2, 1);
    i.addEdgeDj(0, 2, 4);
    i.addEdgeDj(0, 3, 7);
    i.addEdgeDj(3, 2, 2);
    i.addEdgeDj(3, 4, 3);

    cout << i.dijkshtra(0, 4) << endl;
}