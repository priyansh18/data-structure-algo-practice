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

    void breadthFirstSearch(int source, int dest = -1) {
        queue<int> q;
        unordered_map<int, bool> m;
        vector<int> dist(V, 0);
        vector<int> parent(V, -1);

        for (int i = 0; i < V; i++) {
            m[i] = false;
        }

        q.push(source);
        m[source] = true;
        parent[source] = source;
        dist[source] = 0;

        while (!q.empty()) {
            int f = q.front();
            cout << f << ",";
            q.pop();
            for (auto node : l[f]) {
                if (!m[node]) {
                    q.push(node);
                    parent[node] = f;
                    dist[node] = dist[f] + 1;
                    m[node] = true;
                }
            }
        }
        cout << endl;

        // Shortest Distance
        for (int i = 0; i < V; i++) {
            cout << "Shortest Distance to " << i << " is " << dist[i] << endl;
        }

        // Print the path from  a source to the destination
        if (dest != -1) {
            int temp = dest;
            while (temp != source) {
                cout << temp << "---";
                temp = parent[temp];
            }
            cout << source;
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

    g.breadthFirstSearch(1);
    cout << endl;
    g.breadthFirstSearch(1, 6);
}