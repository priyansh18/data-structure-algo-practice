// Course Schedule -- II

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
            cout << i << " : " << i << " -----> ";
            for (auto nbr : l[i]) {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }

    bool containCycle(vector<int>& visited, vector<int>& stack, int src) {
        visited[src] = 1;
        stack[src] = 1;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                bool cycleFound = containCycle(visited, stack, nbr);
                if (cycleFound) {
                    return true;
                }
            }
            if (stack[nbr]) {
                return true;
            }
        }
        stack[src] = 0;
        return false;
    }

    void fillArray(vector<int>& arr) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto nbr : l[i]) {
                indegree[nbr]++;
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
            arr.push_back(front);
            q.pop();
            for (auto nbr : l[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
};

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for (auto x : prerequisites) {
            g.addEdge(x[1], x[0]);
        }

        vector<int> arr;
        bool flag = false;
        for (int i = 0; i < numCourses; i++) {
            vector<int> visited(numCourses, 0);
            vector<int> stack(numCourses, 0);
            if (g.containCycle(visited, stack, i)) flag = true;
        }
        if (flag) {
            cout << "cycle Found";
            return arr;
        } else {
            cout << "cycle not Found";
            g.fillArray(arr);
        }

        return arr;
    }
};

int main() {
    Solution s;
    int numCourses = 4;
    vector<vector<int>> prereq = {{0, 1}, {3, 1}, {1, 3}, {3, 2}};
    vector<int> result = s.findOrder(numCourses, prereq);
    for (auto x : result) {
        cout << x << ",";
    }
}