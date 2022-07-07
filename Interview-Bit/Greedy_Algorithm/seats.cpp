#include <bits/stdc++.h>
using namespace std;

int seats(string A) {
    int n = A.length();
    vector<int> filledPositions;
    for (int i = 0; i < n; i++) {
        if (A[i] == 'x') {
            filledPositions.push_back(i);
        }
    }

    int s = 0;
    int e = filledPositions.size() - 1;
    int mid = (s + e) / 2;
    int jumps = 0;
    for (int i = s; i <= e; i++) {
        int start = filledPositions[i];
        int end = filledPositions[mid] - mid + i;
        jumps += abs(end - start);
    }
    return jumps;
}

int main() {
    string A = "....x..xx...x..";
    cout << seats(A) << endl;
}