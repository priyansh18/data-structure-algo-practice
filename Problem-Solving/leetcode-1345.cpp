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

const int INF = 1e8 + 5;
// Graph Approach
class Solution2 {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        vector<int> visited(n, 0);
        vector<int> dist(n, 0);
        queue<int> q;
        q.push(0);
        q.push(INF);
        visited[0] = 1;
        dist[0] = 0;
        int level = 0;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp == INF) {
                level++;
                if (!q.empty()) q.push(INF);
            } else {
                if (temp == n - 1) return level;
                if (temp - 1 >= 0 and !visited[temp - 1]) {
                    q.push(temp - 1);
                    visited[temp - 1] = 1;
                    dist[temp - 1] = dist[temp] + 1;
                }
                if (temp + 1 < n and !visited[temp + 1]) {
                    q.push(temp + 1);
                    visited[temp + 1] = 1;
                    dist[temp + 1] = dist[temp] + 1;
                }

                vector<int> nbrs = m[arr[temp]];
                for (auto x : nbrs) {
                    if (!visited[x]) {
                        visited[x] = 1;
                        dist[x] = dist[temp] + 1;
                        q.push(x);
                    }
                }

                m.erase(arr[temp]);
            }
        }
        

        return -1;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    vector<int> arr2 = {7, 6, 9, 6, 9, 6, 9, 7};
    vector<int> arr3 = {7, 6, 9, 6, 9, 6, 9, 7};
    cout << s2.minJumps(arr) << endl;
}