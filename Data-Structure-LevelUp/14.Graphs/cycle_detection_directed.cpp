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

    void addEdge(int i, int j, bool undir = false) { l[i].push_back(j); }

    bool dfs(int source, vector<bool>& visited, vector<bool>& stack) {

        // Arrive at node
        visited[source] = true;
        stack[source] = true;

        // Doing some work at the node.
        for (auto nbr : l[source]) {
            if (stack[nbr]) {
                return true;
            } else if (!visited[nbr]) {
                bool nbrFoundACycle = dfs(nbr, visited, stack);
                if (nbrFoundACycle) {
                    return true;
                }
            }
        }

        // Going back
        stack[source] = false;
        return false;
    }

    bool contains_cycle() {
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, stack)) {
                    return true;
                }
            }
        }

        return false;
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