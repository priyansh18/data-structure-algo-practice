#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
}
    priority_queue<int> maxHeap;
    for (auto x : A) {
        maxHeap.push(x);
    }
    int ans = 0;
    while (B--) {
        int val = maxHeap.top();
        maxHeap.pop();
        ans += val;
        maxHeap.push(val - 1);
    }

    return ans;

int main() {
    vector<int> rows = {2, 3};
    int people = 3;
    cout << solve(rows, people);
}