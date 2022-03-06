#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N][N];
int visited[N][N] = {0};

int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int flood_fill(int x, int y) {
    visited[x][y] = 1;
    int cs = 1;

    for (int k = 0; k < 4; k++) {
        int newDx = x + dx[k];
        int newDy = y + dy[k];

        if (newDx >= 0 and newDy >= 0 and newDx < n and newDy < m and
            a[newDx][newDy] == 1 and !visited[newDx][newDy]) {
            int subComp = flood_fill(newDx, newDy);
            cs +=  subComp;
        }
    }

    return cs;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int total_count = 0;
    int biggest_island = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 and !visited[i][j]) {
                total_count++;

                int val = flood_fill(i, j);

                biggest_island = max(biggest_island,val);
            }
        }
    }

    cout << total_count << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << biggest_island << endl;


    return 0;
}