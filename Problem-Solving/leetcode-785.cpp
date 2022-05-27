// Is Graph Bipartite

#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;
    list<int> *l;

    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) { l[u].push_back(v); }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << " i " << i << ":";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    bool isGraphBipartiteHelper(vector<int> &visited, int src, int parent,
                                int color) {
        visited[src] = color;
        for (auto nbr : l[src]) {
            if (visited[nbr] == 0) {
                bool subProblem =
                    isGraphBipartiteHelper(visited, nbr, src, 3 - color);
                if (subProblem == false) {
                    return false;
                }
            } else if (nbr != parent and color == visited[nbr]) {
                return false;
            }
        }

        return true;
    }

    bool isGraphBipartite() {
        int color = 1;
        bool ans = true;
        for (int i = 0; i < V; i++) {
            vector<int> visited(V, 0);  // 0 means not visited
            ans = ans && isGraphBipartiteHelper(visited, i, -1, color);
        }

        return ans;
    }
};

class Solution {
   public:
    bool isBipartite(vector<vector<int>> &graph) {
        Graph g(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (auto x : graph[i]) {
                g.addEdge(i, x);
            }
        }
        g.printList();

        return g.isGraphBipartite();
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << s.isBipartite(graph) << endl;
}