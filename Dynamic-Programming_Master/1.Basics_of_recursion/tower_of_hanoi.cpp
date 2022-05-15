#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char helper, char to) {
    if (n == 0) return;

    towerOfHanoi(n - 1, from, to, helper);
    cout << from << " ---> " << to << endl;
    towerOfHanoi(n - 1, helper, from, to);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
}