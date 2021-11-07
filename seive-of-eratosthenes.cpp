#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sieve[n];
    for (int i = 0; i < n; i++) {
        sieve[i] = true;
    }
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] != false) {
            for (int j = i * i; j < n; j = j + i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (sieve[i]) {
            cout << i << " ";
        }
    }
}