#include <bits/stdc++.h>
using namespace std;

int bulbs(vector<int> &A) {
    int n = A.size();
    int switches = 0;
    for (int i = 0; i < n; i++) {
        if (switches % 2 == 0) {
            if (A[i] == 0) {
                switches++;
                A[i] = 1 - A[i];
            } else {
                continue;
            }
        } else {
            if (A[i] == 0) {
                A[i] = 1 - A[i];
                continue;
            } else {
                switches++;
            }
        }

        
    }
    return switches;
}

int main() {
    vector<int> A = {0, 1, 0, 1};
    cout << bulbs(A) << endl;
}