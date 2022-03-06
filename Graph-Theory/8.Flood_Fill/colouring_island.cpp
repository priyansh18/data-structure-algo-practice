#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N][N];
int visited[N][N] = {0};

int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void flood_fill(int x, int y, int color) {
    a[x][y] = color;
    visited[x][y] = 1;

    for (int k = 0; k < 4; k++) {
        int newDx = x + dx[k];
        int newDy = y + dy[k];

        if (newDx >= 0 and newDy >= 0 and newDx < n and newDy < m and
            a[newDx][newDy] == 1 and !visited[newDx][newDy]) {
            flood_fill(newDx, newDy, color);
        }
    }
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 and !visited[i][j]) {
                total_count++;
                flood_fill(i, j, total_count);
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

    return 0;
}