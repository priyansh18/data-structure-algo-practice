#include <bits/stdc++.h>
using namespace std;

int noOfWaysFriendPaired(int n) {
    if (n == 0 or n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    return noOfWaysFriendPaired(n - 1) + (n - 1) * noOfWaysFriendPaired(n - 2);
}

int main() {
    int n = 10;
    cout << noOfWaysFriendPaired(n);
}