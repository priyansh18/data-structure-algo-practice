
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

    void addEdge(int x, int y) { l[x].push_back(y); }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << "i :" << i << "---> ";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    bool cycleFoundHelper(int src, vector<int> &visited, vector<int> &inStack) {
        visited[src] = 1;
        inStack[src] = 1;

        for (auto nbr : l[src]) {
            if (inStack[nbr]) {
                return true;
            } else if (!visited[nbr]) {
                bool success = cycleFoundHelper(nbr, visited, inStack);
                if (success) return true;
            }
        }
        inStack[src] = 0;
        return false;
    }

    bool cycleFound() {
        vector<int> visited(V, 0);
        vector<int> inStack(V, 0);

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bool success = cycleFoundHelper(i, visited, inStack);
                if (success) return true;
            }
        }

        return false;
    }
};

int solve(int A, vector<vector<int>> &B) {
    Graph g(A + 1);

    for (auto x : B) {
        g.addEdge(x[0], x[1]);
    }

    return g.cycleFound();
}

int main() {
    int A = 5;
    vector<vector<int>> B = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    cout << solve(A, B);
}