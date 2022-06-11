// Number of provinces.

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
        for (int i = 0; i < V; i++) {
            cout << "i : " << i << "---->";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void dfsHelper(int i, vector<int>& visited) {
        visited[i] = 1;
        for (auto nbr : l[i]) {
            if (!visited[nbr]) dfsHelper(nbr, visited);
        }
    }

    int dfs() {
        vector<int> visited(V, 0);
        int group = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited);
                group++;
            }
        }

        return group;
    }
};

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Graph g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) g.addEdge(i, j);
            }
        }

        g.printList();

        return g.dfs();
    }
};

int main() {
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << s.findCircleNum(isConnected);
}