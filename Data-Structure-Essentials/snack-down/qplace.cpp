#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int queens = n - 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (n >= 3 and i == j and i != 0 and i != 2) {
                    cout << "Q";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
}