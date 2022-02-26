#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    list<pair<int, int>> *l;

    Graph(int v) {
        this->V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int i, int j, int wt) {
        l[i].push_back({j, wt});
        l[j].push_back({i, wt});
    }

    void printAdjacencyList() {
        for (int i = 0; i < V; i++) {
            cout << i << " ---> ";
            for (auto nbr : l[i]) {
                cout << nbr.first << "," << nbr.second;
                cout << endl;
            }
            cout << endl;
        }
    }

    int minCostSet(int src) {
        set<pair<int, int>> activeEdge;
        vector<int> visited(V, 0);
        int ans = 0;

        visited[src] = 1;

        for (auto nbr : l[src]) {
            int vertex = nbr.first;
            int wt = nbr.second;
            activeEdge.insert({wt, vertex});
        }

        while (!activeEdge.empty()) {
            auto front = activeEdge.begin();
            activeEdge.erase(front);
            int wt = front->first;
            int vertex = front->second;
            if (visited[vertex] == 1) {
                continue;
            }
            ans += wt;
            visited[vertex] = 1;
            for (auto nbr : l[vertex]) {
                if (!visited[nbr.first]) {
                    activeEdge.insert({nbr.second, nbr.first});
                }
            }
        }

        return ans;
    }

    int minCostQueue(int src) {
        // Initialize a min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            Q;

        // visited arrat that denotes whether a node has been included in MST or
        // not
        vector<bool> visited(V, false);
        int ans = 0;

        // Begin
        Q.push({0, 0});  // weight,node

        while (!Q.empty()) {
            auto front = Q.top();
            Q.pop();

            int wt = front.first;
            int vertex = front.second;

            if (visited[vertex]) {
                // Discard the edge
                continue;
            }
            ans += wt;
            visited[vertex] = true;

            for (auto x : l[vertex]) {
                if (!visited[x.first]) {
                    Q.push({x.second, x.first});
                }
            }
        }

        return ans;
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 12);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 5, 10);
    g.addEdge(3, 6, 8);
    g.addEdge(3, 7, 5);
    g.addEdge(4, 5, 3);
    g.addEdge(5, 7, 6);
    g.addEdge(6, 7, 9);
    g.addEdge(6, 8, 2);
    g.addEdge(7, 8, 11);
    // g.addEdge(0, 1, 1);
    // g.addEdge(0, 2, 2);
    // g.addEdge(0, 3, 2);
    // g.addEdge(1, 2, 2);
    // g.addEdge(1, 3, 3);
    // g.addEdge(2, 3, 3);

    // g.printAdjacencyList();

    cout << g.minCostSet(0);
    cout<<endl;
    cout << g.minCostQueue(0);

    return 0;
}