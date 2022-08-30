
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDeletionSize(vector<vector<char>>& A) {
        int m = A.size(), n = A[0].size(), res = 0;
        vector<bool> check(m - 1, false);
        for (int j = 0; j < n; j++) {
            bool ok = true;
            for (int i = 1; i < m; i++)
                if (!check[i - 1] && A[i][j] < A[i - 1][j]) {
                    ok = false;
                    break;
                }

            if (ok) {
                for (int i = 1; i < m; i++)
                    if (!check[i - 1] && A[i][j] > A[i - 1][j])
                        check[i - 1] = true;
            } else
                res++;
        }
        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> A;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        A[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cout << Solution().minDeletionSize(A) << endl;
    return 0;
}