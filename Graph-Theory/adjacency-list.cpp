#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

struct Graph {
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

    void printShortestPath(int src, int dest) {
        vector<int> dist(V, 0);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);

        queue<int> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto node : l[front]) {
                if (!visited[node]) {
                    q.push(node);
                    dist[node] = dist[front] + 1;
                    parent[node] = front;
                    visited[node] = true;
                }
            }
        }

        if (dest != -1) {
            int temp = dest;
            while (temp != src) {
                cout << temp << " ---> ";
                temp = parent[temp];
            }
            cout << src;
        }
    }
    void printList() {
        for (int i = 0; i < V; i++) {
            cout << "i " << i << " : ";
            for (auto c : l[i]) {
                cout << c << ",";
            }
            cout << endl;
        }
    }

    void breadthFirstSearch(int src) {
        queue<int> q;
        bool* visited = new bool[V]{false};
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            cout << front << ",";
            for (auto node : l[front]) {
                if (!visited[node]) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }

    void depthFirstSearchHelper(int src, vector<bool>& visited) {
        visited[src] = true;
        cout << src << ",";
        for (auto node : l[src]) {
            if (!visited[node]) {
                depthFirstSearchHelper(node, visited);
            }
        }
    }

    void depthFirstSearch(int src) {
        vector<bool> visited(V, false);
        depthFirstSearchHelper(src, visited);
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

    g.printList();

    g.breadthFirstSearch(1);

    cout << endl;

    g.depthFirstSearch(0);

    cout << endl;

    g.printShortestPath(1, 6);
}