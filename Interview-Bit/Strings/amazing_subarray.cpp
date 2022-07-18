#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    int n = A.length();
    int k = n;
    int i = 0;
    int count = 0;
    while (i < n) {
        if (A[i] == 'A' or A[i] == 'E' or A[i] == 'I' or A[i] == 'O' or
            A[i] == 'U') {
            count += k;
        }
        i++;
        k--;
    }

    return count;
}

int main() {
    string str = "ABEC";
    cout << solve(str);
}