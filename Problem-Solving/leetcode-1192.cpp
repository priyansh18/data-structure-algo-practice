// Critical Connection in a network.

#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;
    list<int>* l;
    int time = 1;

    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << " i : " << i << "-----> ";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void criticalEdge(int src, int parent, vector<int>& visited,
                      vector<int>& discovered, vector<int>& lowest,
                      vector<vector<int>>& result) {
        visited[src] = 1;
        discovered[src] = lowest[src] = time++;
        int child = 0;

        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                criticalEdge(nbr, src, visited, discovered, lowest,result);
                child++;
                // We already know lowest and discovered time of nbr.
                lowest[src] = min(lowest[src], lowest[nbr]);

                // Bridge
                if (lowest[nbr] > discovered[src]) {
                    vector<int> res;
                    res.push_back(src);
                    res.push_back(nbr);
                    result.push_back(res);
                }

            } else if (nbr != parent)
                // Backedge
                lowest[src] = min(lowest[src], discovered[nbr]);
        }

        return;
    }
};

class Solution {
   public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        Graph g(n);
        vector<vector<int>> result;

        for (auto x : connections) {
            g.addEdge(x[0], x[1]);
        }

        vector<int> visited(n);
        vector<int> discovered(n);
        vector<int> lowest(n);

        g.printList();

        g.criticalEdge(0, -1, visited, discovered, lowest,result);

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int n = 4;
    vector<vector<int>> result = s.criticalConnections(n, connections);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}