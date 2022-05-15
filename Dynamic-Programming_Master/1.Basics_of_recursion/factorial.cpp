#include <bits/stdc++.h>
using namespace std;

int computeFactorial(int N) {
    if (N == 0 or N == 1) {
        return 1;
    }
    return N * computeFactorial(N - 1);
}

int main() {
    int n;
    cin >> n;
    cout << computeFactorial(n) << endl;

    return 0;
}