#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
   public:
    int V;
    list<int>* l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }

    bool dfs(int node, vector<bool>& visited, int parent) {
        visited[node] = true;

        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                bool cycleFound = dfs(nbr, visited, node);
                if (cycleFound) {
                    return true;
                }
                // nbr is visited and its not the parent of current node in current dfs call
            } else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle() {
        vector<bool> visited(V, false);
        return dfs(0, visited, -1);
    }
};

int main() {
    Graph g(3);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    g.contains_cycle() ? cout << "Cycle Detected"
                       : cout << "Cycle Not Detected";
}