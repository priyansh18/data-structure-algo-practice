// Oliver & the game

#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> &v, int parent, vector<int> &inTime,
         vector<int> &outTime, int &timer) {
    inTime[src] = timer++;
    for (auto x : v[src]) {
        if (x != parent) {
            dfs(x, v, src, inTime, outTime, timer);
        }
    }

    outTime[src] = timer++;
}

bool check(int x, int y, vector<int> &inTime, vector<int> &outTime) {
    if (inTime[x] > inTime[y] and outTime[x] < outTime[y]) return true;
    return false;
}

bool possibleToSearch(int n, vector<vector<int>> edges, int mansion, int x,
                      int y) {
    vector<vector<int>> v(n + 1);
    for (auto x : edges) {
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
    }
    int timer = 1;
    vector<int> inTime(n + 1, 0);
    vector<int> outTime(n + 1, 0);

    dfs(1, v, 0, inTime, outTime, timer);

    if (mansion == 0) {
        return check(y, x, inTime, outTime);
    }
    return check(y, x, inTime, outTime);
}

int main() {
    int n;
    cin >> n;
    int k = n - 1;
    vector<vector<int>> edges;
    while (k--) {
        vector<int> r;
        int a, b;
        cin >> a >> b;
        r.push_back(a);
        r.push_back(b);
        edges.push_back(r);
    }
    int mansion;
    int x;
    int y;
    cin >> mansion >> x >> y;
    cout << possibleToSearch(n, edges, mansion, x, y);
}