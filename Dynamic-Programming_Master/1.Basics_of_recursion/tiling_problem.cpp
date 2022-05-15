#include <bits/stdc++.h>
using namespace std;

int noOfWaysToPlaceTile(int n) {
    if (n <= 3) {
        return 1;
    }
    return noOfWaysToPlaceTile(n - 1) + noOfWaysToPlaceTile(n - 4);
}

int main() {
    int n = 4;
    cout << noOfWaysToPlaceTile(n);
}