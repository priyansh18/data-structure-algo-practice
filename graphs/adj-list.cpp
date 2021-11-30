#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
using namespace std;
class Graph {
    int vertices;
    list<int> *l;

   public:
    Graph(int v) {
        this->vertices = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }

    void printAdjList() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " --->>> ";
            for (auto node : l[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    // Time Complexity of both BFS & DFS is O(V+E).

    void breadthFirstSearch(int source) {
        queue<int> q;
        bool *visited = new bool[vertices]{false};
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int temp = q.front();
            cout << temp << "-->";
            q.pop();

            // Push the neighbours inside queue if they are not already visited.
            for (auto nbr : l[temp]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfsHelper(int node, bool *visited) {
        visited[node] = true;
        cout << node << "-->";
        // Make a dfs call on all it's unvisited neighbours.
        for (int nbrs : l[node]) {
            if (!visited[nbrs]) {
                dfsHelper(nbrs, visited);
            }
        }
        return;
    }

    void depthFirstSearch(int source) {
        bool *visited = new bool[vertices]{false};
        dfsHelper(source, visited);
    }

    void topologicOrdering() {
        vector<int> indegree(vertices, 0);

        // Iterate over all the edges to find the right indegree.
        for (int i = 0; i < vertices; i++) {
            for (auto nbr : l[i]) {
                indegree[nbr]++;
            }
        }

        // Bfs
        queue<int> q;
        // Initialize the q with nodes having 0 indegree.
        for (int i = 0; i < vertices; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // Start popping nodes.
        while (!q.empty()) {
            int temp = q.front();
            cout << temp << "-->";
            q.pop();
            for (auto nbr : l[temp]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
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
    g.breadthFirstSearch(1);
    cout << endl;
    g.depthFirstSearch(1);
    cout << endl;
    g.printAdjList();

    cout << endl;

    Graph h(6);
    h.addEdge(0, 2, false);
    h.addEdge(2, 3, false);
    h.addEdge(3, 5, false);
    h.addEdge(4, 5, false);
    h.addEdge(1, 4, false);
    h.addEdge(1, 2, false);

    h.printAdjList();

    h.topologicOrdering();
}