#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int totalSteps = 0;
        int diff = abs(x - y);
        if (x > y) {
            totalSteps = diff;
        } else {
            if (diff % 2 == 0) {
                totalSteps = totalSteps + diff / 2;
            } else {
                totalSteps += diff / 2 + 2;
            }
        }
        cout << totalSteps<<endl;
    }
}