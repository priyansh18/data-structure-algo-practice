

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
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycleDetection(int src, vector<int> &visited, int parent) {
        visited[src] = 1;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                bool success = cycleDetection(nbr, visited, src);
                if (success) return true;
            } else if (nbr != parent) {
                return true;
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
    vector<int> visited(A, 0);
    for (int i = 0; i < A; i++) {
        if (!visited[i + 1]) {
            bool success = g.cycleDetection(i + 1, visited, -1);
            if (success) return true;
        }
    }

    return false;
}

bool cycleDetection(vector<vector<int>> &v, int src, vector<int> &visited,
                    int parent) {
    visited[src] = 1;
    for (auto nbr : v[src]) {
        if (!visited[nbr]) {
            bool success = cycleDetection(v, nbr, visited, src);
            if (success) return true;
        } else if (nbr != parent) {
            return true;
        }
    }

    return false;
}

int solve2(int A, vector<vector<int>> &B) {
    vector<vector<int>> v(A + 1);

    for (int i = 0; i < B.size(); i++) {
        v[B[i][1]].push_back(B[i][0]);
        v[B[i][0]].push_back(B[i][1]);
    }

    vector<int> visited(A + 1, 0);
    for (int i = 0; i < A; i++) {
        if (!visited[i + 1]) {
            bool success = cycleDetection(v, i + 1, visited, -1);
            if (success) return true;
        }
    }

    return false;
}

int main() {
    int A = 5;
    vector<vector<int>> B = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {4, 5}};
    cout << solve2(A, B);
}
