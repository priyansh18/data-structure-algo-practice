#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int key;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> key;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int i = m - 1, j = 0;

    while (i > 0 or j < n) {
        if (arr[i][j] == key) {
            cout << "Element Found at Index " << i << "," << j;
            break;
        } else if (arr[i][j] > key) {
            i--;
        } else {
            j++;
        }
    }
}