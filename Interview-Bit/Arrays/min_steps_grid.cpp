#include <bits/stdc++.h>
using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < A.size(); i++) {
        v[i].first = A[i];
        v[i].second = B[i];
    }
    for (auto x : v) {
        cout << x.first << " and " << x.second << endl;
    }

    int i = 0;
    int j = 1;
    int moves = 0;
    while (j < n) {
        int xx = v[j].first - v[i].first;
        int yy = v[j].second - v[i].second;
        moves += max(xx, yy);
        i++;
        j++;
    }

    return moves;
}

int main() {
    vector<int> A = {0, 1, 1};
    vector<int> B = {0, 1, 2};
    cout << coverPoints(A, B) << endl;
}