#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;

    while (row_start <= row_end and col_start <= col_end) {
        // Tranversing top row
        for (int i = col_start; i <= col_end; i++) {
            cout << arr[row_start][i] << " ";
        }

        // Transversing right column
        for (int i = row_start + 1; i <= row_end; i++) {
            cout << arr[i][col_end] << " ";
        }

        // Transversing bottom row
        for (int i = col_end - 1; i >= col_start; i--) {
            // Avoid Repeated Printing
            if (row_start == row_end) {
                break;
            }
            cout << arr[row_end][i] << " ";
        }

        // Transversing left column
        for (int i = row_end - 1; i >= row_start + 1; i--) {
            // Avoid Repeated Printing

            if (col_start == col_end) {
                break;
            }
            cout << arr[i][col_start] << " ";
        }

        row_start++;
        col_end--;
        row_end--;
        col_start++;
    }
}
