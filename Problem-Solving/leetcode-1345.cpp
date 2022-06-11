// Jump Game IV

#include <bits/stdc++.h>
using namespace std;

// O(3^n *n) Time Limit Exceed
class Solution1 {
   public:
    int minJumpsHelper(vector<int> arr, int s, int e, vector<int>& visited) {
        if (s < 0 or s > e) return 1e9;
        if (s == e) return 0;

        if (!visited[s]) {
            visited[s] = 1;
            int opt1 = minJumpsHelper(arr, s + 1, e, visited);
            int opt2 = minJumpsHelper(arr, s - 1, e, visited);
            int opt3 = 1e9;
            for (int i = 0; i <= e; i++) {
                if (i != s and arr[i] == arr[s]) {
                    opt3 = min(opt3, minJumpsHelper(arr, i, e, visited));
                }
            }
            visited[s] = 0;
            return min({opt1, opt2, opt3}) + 1;
        }

        return 1e9;
    }

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> visited(n, 0);
        return minJumpsHelper(arr, 0, n - 1, visited);
    }
};

class Graph {
   public:
    int V;
    set<int>* l;

    Graph(int v) {
        this->V = v;
        l = new set<int>[V];
    }

    void addEdge(int x, int y) { l[x].insert(y); }

    void printList(vector<int> arr, int n) {
        for (int i = 0; i < n; i++) {
            cout << " i : " << i << "-----> ";
            for (auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    int bfs(int src, int dest) {
        vector<int> visited(V, false);
        queue<int> q;
        q.push(src);
        q.push(-1);
        visited[src] = 1;
        int level = 0;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp == -1) {
                level++;
                if (!q.empty()) q.push(-1);
            } else {
                if (temp == dest) return level;
                for (auto x : l[temp])
                    if (!visited[x]) {
                        q.push(x);
                    }
            }
        }

        return -1;
    }
};

// Graph Approach
class Solution2 {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        Graph g(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) g.addEdge(i, i + 1);
            if (i - 1 >= 0) g.addEdge(i, i - 1);
            for (int j = 0; j < n; j++) {
                if (i != j and arr[i] == arr[j]) {
                    g.addEdge(i, j);
                }
            }
        }

        g.printList(arr, n);

        return g.bfs(0, n - 1);
    }
};

class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int index = q.front();
                q.pop();
                if (index == n - 1) return step;
                for (int x : m[arr[index]]) {
                    if (!visited[x]) {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
                if (index + 1 < n and !visited[index + 1]) {
                    q.push(index + 1);
                    visited[index + 1] = 1;
                }
                if (index - 1 >= 0 and !visited[index - 1]) {
                    q.push(index - 1);
                }
            }
            step++;
        }
        return step;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    Solution s;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    vector<int> arr2 = {7, 6, 9, 6, 9, 6, 9, 7};
    vector<int> arr3 = {7, 6, 9, 6, 9, 6, 9, 7};
    cout << s.minJumps(arr) << endl;
    cout << s2.minJumps(arr2) << endl;
    cout << s.minJumps(arr3) << endl;
}