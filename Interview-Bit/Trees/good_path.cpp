#include <bits/stdc++.h>
using namespace std;

void findScore(vector<vector<int>> vertices, int src, vector<int> arr,
               float &pathLength, map<int, int> &m, int &goodPath) {
    for (auto nbr : vertices[src]) {
        m[arr[nbr - 1]]++;
        pathLength++;

        for (auto x : m) {
            if (x.second >= ceil(pathLength / 2)) {
                goodPath++;
                break;
            }
        }
        findScore(vertices, nbr, arr, pathLength, m, goodPath);
        m[arr[nbr - 1]]--;
        pathLength--;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        vector<vector<int>> vertices(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a;
            int b;
            cin >> a >> b;
            vertices[a].push_back(b);
        }
        map<int, int> m;
        m[1] = arr[0];
        float pathLength = 1;
        int goodPath = 1;
        findScore(vertices, 1, arr, pathLength, m, goodPath);
        cout << goodPath << endl;
    }
}