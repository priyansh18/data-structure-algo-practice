#include <bits/stdc++.h>
using namespace std;

#include <list>

class Graph {
   public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) { l[min(x, y)].push_back(max(x, y)); }

    void dfs(vector<int> &A, int src, int C, int count, int &path) {
        if (l[src].size() == 0 and count <= C) {
            path++;
            return;
        }
        for (auto nbr : l[src]) {
            if (A[nbr - 1] == 1) {
                dfs(A, nbr, C, count + 1, path);
            } else {
                dfs(A, nbr, C, count, path);
            }
        }
    }
};

int solve(vector<int> &A, vector<vector<int>> &B, int C) {
    int n = A.size();
    Graph g(n + 1);

    for (auto x : B) {
        g.addEdge(x[0], x[1]);
    }

    int path = 0;
    g.dfs(A, 1, C, A[0], path);
    return path;
}

int main() {
    vector<int> A = {0, 1, 0, 1, 1, 1};
    vector<vector<int>> B = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
    int C = 1;
    cout << solve(A, B, C);
}
