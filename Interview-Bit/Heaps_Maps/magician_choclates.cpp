#include <bits/stdc++.h>
using namespace std;

int nchoc(int A, vector<int> &B) {
    priority_queue<int> maxHeap;
    const int M = 1000000007;
    for (auto x : B) {
        maxHeap.push(x);
    }
    int ans = 0;
    while (A--) {
        int val = maxHeap.top();
        maxHeap.pop();
        ans += val;
        maxHeap.push(floor(val / 2));
    }

    return (long long)ans % M;
}

int main() {
    int A = 5;
    vector<int> B = {2, 4, 6, 8, 10};
    cout << nchoc(A, B);
}