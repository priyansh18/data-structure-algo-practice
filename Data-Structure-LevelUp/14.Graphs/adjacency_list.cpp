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

    void printAdjacencyList() {
        for (int i = 0; i < V; i++) {
            cout << i << "-->";
            for (auto node : l[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.printAdjacencyList();
}