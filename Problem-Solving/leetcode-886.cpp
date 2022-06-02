// Possible Bipartition

#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;
    list<int>* l;

    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) { l[x].push_back(y); }

    void printList() {
        for (int i = 0; i < V - 1; i++) {
            cout << "i  : " << i + 1 << " -----> ";
            for (auto x : l[i + 1]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    bool isBipartite(int src, int parent, vector<int>& visited, int color) {
        visited[src] = color;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                bool possible = isBipartite(nbr, src, visited, 3 - color);
                if (!possible) {
                    return false;
                }
            }
            if (nbr != parent and visited[nbr] == color) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
   public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        Graph g(n + 1);

        for (auto x : dislikes) {
            g.addEdge(x[0], x[1]);
        }

        g.printList();

        bool flag = true;
        for (int i = 1; i <= n; i++) {
            vector<int> visited(n + 1, 0);
            int color = 1;
            if (!g.isBipartite(i, -1, visited, color)) flag = false;
        }

        return flag;
    }
};

int main() {
    Solution s;
    int n = 5;
    vector<vector<int>> dislikes = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << s.possibleBipartition(n, dislikes);
}