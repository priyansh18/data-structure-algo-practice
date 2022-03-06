#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool direc = true) { l[x].push_back(y); }

    // BFS - Kahn's Algo

    void topologicalSort(vector<int> &indegree) {
        for (int i = 0; i < V; i++) {
            for (auto x : l[i]) {
                indegree[x]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            cout << front << "--->";
            q.pop();
            for (auto nbr : l[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    bool cycleDetected() {
        vector<int> indegree(V, 0);

        topologicalSort(indegree);

        cout << endl;

        for (auto x : indegree) {
            if (x != 0) {
                return true;
            }
        }

        return false;
    }

    // DFS

    void dfsHelper(int node, vector<bool> &visited, list<int> &li) {
        visited[node] = true;
        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                dfsHelper(nbr, visited, li);
            }
        }
        li.push_front(node);
    }

    void dfs(int src) {
        vector<bool> visited(V, false);
        list<int> li;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited, li);
            }
        }

        for (auto x : li) {
            cout << x << ",";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);

    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,1);

    // cout << g.cycleDetected();
    g.dfs(0);
}