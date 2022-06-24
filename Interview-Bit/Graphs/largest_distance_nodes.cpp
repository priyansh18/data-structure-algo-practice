#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[min(x,y)].push_back(max(x,y));
    }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << "i :" << i << "---> ";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void dfs(int src, vector<int> &visited, int &dist) {
        visited[src] = 1;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                dist++;
                dfs(nbr, visited, dist);
            }
        }
    }
};

int solve(vector<int> &A) {
    int n = A.size();
    Graph g(n);

    for (int i = 0; i < n; i++) {
        if (A[i] != -1) {
            g.addEdge(i, A[i]);
        }
    }

    g.printList();
    int maxDist = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (A[i] == -1) {
            vector<int> visited(n, 0);
            return g, dfs(i);
        }
    }
}

int main() {
    vector<int> A = {-1, 0, 0, 0, 3};
    cout << solve(A);
}