
#include <list>

class Graph {
   public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) { l[x].push_back(y); }

    bool dfsHelper(int src, vector<int> &visited, int dest) {
        visited[src] = 1;
        if (src == dest) return true;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                bool success = dfsHelper(nbr, visited, dest);
                if (success) return true;
            }
        }

        return false;
    }

    bool dfs(int src, int dest) {
        vector<int> visited(V, 0);
        return dfsHelper(src, visited, dest);
    }

    bool bfs(int src, int dest) {
        queue<int> q;
        vector<int> visited(V, 0);
        q.push(src);
        visited[src] = 1;
        while (!q.empty()) {
            auto temp = q.front();
            if (temp == dest) return true;
            q.pop();
            for (auto nbr : l[temp]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                }
            }
        }
        return false;
    }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    Graph g(A + 1);

    for (auto x : B) {
        g.addEdge(x[0], x[1]);
    }

    return g.dfs(1, A);
}
