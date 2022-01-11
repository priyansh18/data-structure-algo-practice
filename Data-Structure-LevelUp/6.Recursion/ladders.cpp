#include <iostream>
using namespace std;

int NumberOfWaysClimbLadder(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    // Only 1,2 & 3 step can be taken.
    return NumberOfWaysClimbLadder(n - 1) + NumberOfWaysClimbLadder(n - 2) +
           NumberOfWaysClimbLadder(n - 3);
}

int main() {
    int n;
    cin >> n;
    cout << NumberOfWaysClimbLadder(n) << endl;
}