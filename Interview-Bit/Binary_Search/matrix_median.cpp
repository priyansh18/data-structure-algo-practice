#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;
    int medianPosition = ((n * m) + 1) / 2;
    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                     matrix[i].begin();
        }

        if (count < medianPosition) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << solve(matrix) << endl;
}