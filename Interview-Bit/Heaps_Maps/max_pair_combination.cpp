#include <bits/stdc++.h>
using namespace std;

class valPair {
   public:
    int sum;
    int x;
    int y;

    valPair(int sum, int x, int y) {
        this->sum = sum;
        this->x = x;
        this->y = y;
    }
};

class Compare {
   public:
    bool operator()(valPair A, valPair B) { return A.sum < B.sum; }
};

vector<int> solve(vector<int> &A, vector<int> &B) {
    priority_queue<valPair, vector<valPair>, Compare> p;
    vector<int> result;
    int m = A.size();
    int n = B.size();
    int k = n;

    int i = m - 1;
    while (i >= 0) {
        p.push({A[i] + B[n - 1], i, n - 1});
        i--;
    }

    while (!p.empty() and k--) {
        /* code */
        auto first = p.top();
        p.pop();
        result.push_back(first.sum);
        if (first.y - 1 >= 0) {
            p.push({A[first.x] + B[first.y - 1], first.x, first.y - 1});
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    vector<int> result = solve(nums1, nums2);
    for (auto x : result) {
        cout << x << ",";
    }
}
