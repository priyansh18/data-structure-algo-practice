// Redundant Connections

#include <bits/stdc++.h>
using namespace std;

class Solution;

struct Graph {
    int V;
    list<int>* l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed = true) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << " i " << i + 1 << ":";
            for (auto x : l[i + 1]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    friend class Solution;
};

class Solution {
   public:
    void dfs(int src, vector<bool>& visited, int parent, vector<int>& result,
             list<int>* l) {
        visited[src] = true;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, src, result, l);
            } else if (nbr != parent) {
                if (parent == -1) {
                    continue;
                }
                result.push_back(nbr);
                result.push_back(src);
            }
        }
    }

    void finalAnswer(vector<vector<int>> answer, vector<vector<int>>& edges,
                     vector<int>& a) {
        for (int i = edges.size() - 1; i >= 0; i--) {
            for (auto x : answer) {
                if (edges[i][1] == x[1] and edges[i][0] == x[0]) {
                    a.push_back(x[0]);
                    a.push_back(x[1]);
                    return;
                }
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> answer;
        int n = edges.size();
        Graph g(n + 1);
        for (auto x : edges) {
            g.addEdge(x[0], x[1]);
        }
        // g.printList();
        for (int i = 0; i < n; i++) {
            vector<int> res;
            vector<bool> visited(n + 1, false);
            dfs(i + 1, visited, -1, res, g.l);
            answer.push_back(res);
        }
        vector<int> a;
        finalAnswer(answer, edges, a);
        return a;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};
    vector<int> res = s.findRedundantConnection(edges);
    for (auto x : res) {
        cout << x << ",";
    }
}