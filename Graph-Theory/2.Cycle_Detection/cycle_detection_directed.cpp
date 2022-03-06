#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Graph {
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed = true) { l[x].push_back(y); }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << " i " << i << ":";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    bool dfs_directed(int node, vector<bool> &visited, vector<bool> &stack) {
        visited[node] = true;
        stack[node] = true;

        for (auto nbr : l[node]) {
            if (stack[nbr] == true) {
                return true;
            } else if (visited[nbr] == false) {
                bool nbrFoundACycle = dfs_directed(nbr, visited, stack);
                if (nbrFoundACycle) {
                    return true;
                }
            }
        }

        stack[node] = false;
        return false;
    }

    bool cycle_detection(int src) {
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs_directed(i, visited, stack)) {
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

    g.printList();

    cout << endl;

    cout << g.cycle_detection(0) << endl;
}