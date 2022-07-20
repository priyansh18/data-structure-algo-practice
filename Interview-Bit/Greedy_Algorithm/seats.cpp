#include <bits/stdc++.h>
using namespace std;

int seats(string A) {
    int n = A.length();
    vector<int> filledPositions;
    for (int i = 0; i < n; i++) {
        if (A[i] == 'R') {
            filledPositions.push_back(i);
        }
    }

    int s = 0;
    int e = filledPositions.size() - 1;
    int mid = (s + e) / 2;
    long jumps = 0;
    for (int i = s; i <= e; i++) {
        int start = filledPositions[i];
        int end = filledPositions[mid] - mid + i;
        int temp = abs(end - start);
        cout << start << " " << temp << endl;
        jumps += temp;
    }
    return jumps;
}

int main() {
    string A = "WWRWWWRWR";
    cout << seats(A) << endl;
}

