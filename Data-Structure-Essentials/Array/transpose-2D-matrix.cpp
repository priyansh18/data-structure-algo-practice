#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    // Getting Array Input from user
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Transpose
    // Direct Printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                cout << arr[i][j] << " ";
            } else {
                cout << arr[j][i] << " ";
            }
        }
        cout << endl;
    }

    // First swap then Print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i <= j) {
                swap(arr[i][j], arr[j][i]);
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}