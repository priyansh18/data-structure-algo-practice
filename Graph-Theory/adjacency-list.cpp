#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

struct Graph {
    int V;
    list<int>* l;

    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }

    void printShortestPath(int src, int dest) {
        vector<int> dist(V, 0);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);

        queue<int> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto node : l[front]) {
                if (!visited[node]) {
                    q.push(node);
                    dist[node] = dist[front] + 1;
                    parent[node] = front;
                    visited[node] = true;
                }
            }
        }

        if (dest != -1) {
            int temp = dest;
            while (temp != src) {
                cout << temp << " ---> ";
                temp = parent[temp];
            }
            cout << src;
        }
    }
    
    void printList() {
        for (int i = 0; i < V; i++) {
            cout << "i " << i << " : ";
            for (auto c : l[i]) {
                cout << c << ",";
            }
            cout << endl;
        }
    }

    void breadthFirstSearch(int src) {
        queue<int> q;
        bool* visited = new bool[V]{false};
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            cout << front << ",";
            for (auto node : l[front]) {
                if (!visited[node]) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }

    void depthFirstSearchHelper(int src, vector<bool>& visited) {
        visited[src] = true;
        cout << src << ",";
        for (auto node : l[src]) {
            if (!visited[node]) {
                depthFirstSearchHelper(node, visited);
            }
        }
    }

    void depthFirstSearch(int src) {
        vector<bool> visited(V, false);
        depthFirstSearchHelper(src, visited);
    }

    int dfs(vector<vector<int>> grid, vector<vector<bool>>& visited, int i,
            int j, int m, int n) {
        visited[i][j] = true;
        int current_size = 1;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];

            if (newX >= 0 and newY >= 0 and newX < m and newY < n and
                grid[newX][newY] == 1 and !visited[newX][newY]) {
                int subComponent = dfs(grid, visited, newX, newY, m, n);
                current_size += subComponent;
            }
        }

        return current_size;
    }

    int largestIsland(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int largest_island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] and grid[i][j] == 1) {
                    int value = dfs(grid, visited, i, j, m, n);
                    largest_island = max(largest_island, value);
                }
            }
        }

        return largest_island;
    }

    bool dfsCycle(int node, vector<bool>& visited, vector<int>& parent) {
        
        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                parent[nbr] = node;
                visited[node] = true;
                if (dfsCycle(nbr, visited, parent)) {
                    return true;
                }
            } else if (parent[node] != nbr) {
                return true;
            }
        }

        return false;
    }

    bool cycleDetectionUndirected(int src) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        return dfsCycle(src, visited, parent);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 0);

    g.printList();

    g.breadthFirstSearch(1);

    cout << endl;

    g.depthFirstSearch(0);

    cout << endl;

    g.printShortestPath(0, 5);

    cout << endl;

    vector<vector<int>> grid = {{1, 0, 0, 1, 0},
                                {1, 0, 1, 0, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 0, 1, 1, 0}};

    cout << g.largestIsland(grid) << endl;

    cout << g.cycleDetectionUndirected(0) << endl;
}