#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pii pair<int, int>

void kWayMergeBetter(vector<int> A, vector<int> B, vector<int> C) {
    int i = 0, j = 0, k = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;

    q.push({A[i], 0});
    q.push({B[j], 1});
    q.push({C[k], 2});

    while (!q.empty()) {
        pii newEl = q.top();
        int ele = newEl.first;
        int warray = newEl.second;
        cout << ele << ",";
        q.pop();
        if (warray == 0) {
            i++;
            if (i < A.size()) q.push({A[i],warray});
            continue;
        }
        if (warray == 1) {
            j++;
            if (j < B.size()) q.push({B[j],warray});
            continue;
        }
        if (warray == 2) {
            k++;
            if (k < C.size()) q.push({C[k],warray});
        }
    }
}

void kWayMerge(vector<int> A, vector<int> B, vector<int> C) {
    int i = 0, j = 0, k = 0;
    priority_queue<int, vector<int>, greater<int> > q;

    q.push(A[i]);
    q.push(B[j]);
    q.push(C[k]);

    while (!q.empty()) {
        int newEl = q.top();
        cout << newEl << ",";
        q.pop();
        if (A[i] == newEl) {
            i++;
            if (i < A.size()) q.push(A[i]);
        } else if (j < B.size() and B[j] == newEl) {
            j++;
            if (j < B.size()) q.push(B[j]);
        } else if (k < C.size() and C[k] == newEl) {
            k++;
            if (k < C.size()) q.push(C[k]);
        } else {
            continue;
        }
    }
    return;
}

int main() {
    vector<int> a1{1, 3, 3, 3, 15};
    vector<int> a2{2, 2, 2};
    vector<int> a3{2, 9, 10, 10, 11};

    kWayMerge(a1, a2, a3);
    cout<<endl;
    kWayMergeBetter(a1, a2, a3);
}