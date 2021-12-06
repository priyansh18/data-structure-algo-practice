#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int no_of_laddus, arr_size;
        cin >> no_of_laddus;
        arr_size = pow(2, no_of_laddus);
        int A[arr_size];
        for (int i = 0; i < arr_size; i++) {
            cin >> A[i];
        }
        sort(A, A + arr_size);
        int i = 0;
        int j = arr_size - 1;

        if (A[i] - A[j] > 1) {
            cout << "No";
        } else {
            cout << "YES";
        }
    }
}
