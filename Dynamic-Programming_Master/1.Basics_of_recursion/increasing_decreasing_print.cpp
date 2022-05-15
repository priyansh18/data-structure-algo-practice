#include <bits/stdc++.h>
using namespace std;

void increasing_sequence(int n) {
    if (n == 0) {
        return;
    }
    increasing_sequence(n - 1);
    cout << n << " ";
}

void decreasing_sequence(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    decreasing_sequence(n - 1);
}

int main() {
    int n = 5;
    increasing_sequence(n);
    cout << endl;
    decreasing_sequence(n);
}