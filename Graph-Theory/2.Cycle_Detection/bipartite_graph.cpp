#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct bipartite_graph {
    int V;
    list<int> *l;

    bipartite_graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool undir = true) {
        l[x].push_back(y);
        if (undir) {
            l[y].push_back(x);
        }
    }

    bool dfs_helper(int node, vector<int> &visited, int parent, int color) {
        visited[node] = color;
        for (auto nbr : l[node]) {
            if (visited[nbr] == 0) {
                int subProblem = dfs_helper(nbr, visited, node, 3 - color);
                if (subProblem == false) {
                    return false;
                }
            } else if (nbr != parent and color == visited[nbr]) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int source) {
        vector<int> visited(V, 0);  // 0 -- Not Visited ,
                                    // 1-- Visited with color 1 ,
                                    // 2-- Visited with color 2

        int color = 1;

        return dfs_helper(source, visited, -1, color);
    }
};

int main() {
    bipartite_graph b(6);
    b.addEdge(0, 1);
    b.addEdge(1, 2);
    b.addEdge(2, 3);
    b.addEdge(3, 4);
    b.addEdge(4, 5);
    b.addEdge(5, 0);

    b.dfs(0) ? cout << "Yes , Graph is Bipartite"
             : cout << "No , Graph is not Bipartite";
}