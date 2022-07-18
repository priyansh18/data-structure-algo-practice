#include <bits/stdc++.h>
using namespace std;

string solve(string A, int B) {
    string output = "";
    int n = A.length();
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (A[i] == A[j]) {
            j++;
        }
        if (j - i == B) {
            i = j;
        } else {
            output += A[i];
            i++;
        }
    }

    return output;
}

int main() {
    string A = "aabbccd";
    int B = 2;
    cout << solve(A, B);
}