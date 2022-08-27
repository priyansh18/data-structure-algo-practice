#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m;
        cout << (n / m + n % m) << endl;
    }

    return 0;
}