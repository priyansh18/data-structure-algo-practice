// First Negative number in every window of size k

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N,
                                            long long int K) {
    vector<long long> result;
    int i = 0;
    int j = 0;
    deque<int> q;
    while (j < N) {
        // Increase window size to K
        if (A[j] < 0) q.push_back(A[j]);
        if (j - i + 1 < K) {
            j++;
        } else {
            if (q.empty()) {
                result.push_back(0);
            } else {
                result.push_back(q.front());
            }
            if (A[i] == q.front()) q.pop_front();
            i++;
            j++;
        }
    }
    return result;
}

int main() {
    int N = 5;
    long long int A[] = {-8, 2, 3, -6, 10};
    int K = 2;
    vector<long long> result = printFirstNegativeInteger(A, N, K);
    for (auto x : result) cout << x << ",";
}