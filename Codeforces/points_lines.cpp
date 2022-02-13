#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> sx, sy;

        while (n--) {
            int x, y;
            cin >> x >> y;
            sx.insert(x);
            sy.insert(y);
        }

        cout << sx.size() + sy.size() << endl;
    }
}