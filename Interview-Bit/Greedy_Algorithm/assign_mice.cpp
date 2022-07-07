#include <bits/stdc++.h>
using namespace std;

int mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;

    for (int i = 0; i < A.size(); i++) {
        ans = max(ans, abs(A[i] - B[i]));
    }

    return ans;
}

int main() {
    vector<int> A = {-4, 2, 3};
    vector<int> B = {0, -2, 4};
    cout << mice(A, B) << endl;
}