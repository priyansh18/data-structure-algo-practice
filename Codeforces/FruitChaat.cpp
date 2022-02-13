#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        a / 2 <= b ? cout << a / 2 : cout << b;
        cout << endl;
    }
}