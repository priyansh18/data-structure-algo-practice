#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int x) {
    if (x == 0) {
        return true;
    }

    return arr[x] > arr[x - 1];
}

int searchLeft(vector<int> &arr, int s, int e, int x) {
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return -1;
}

int searchRight(vector<int> &arr, int s, int e, int x) {
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return -1;
}

int solve(vector<int> &A, int B) {
    int peak;
    int s = 0;
    int e = A.size() - 1;
    int n = A.size();
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (check(A, mid)) {
            peak = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    if (A[peak] == B) return peak;
    int ans1 = searchLeft(A, 0, peak - 1, B);
    int ans2 = searchRight(A, peak + 1, n - 1, B);

    if (ans1 != -1) return ans1;
    if (ans2 != -1) return ans2;
    return -1;
}

int main() {
    vector<int> nums = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    int k = 8;
    cout << solve(nums, k) << endl;
}