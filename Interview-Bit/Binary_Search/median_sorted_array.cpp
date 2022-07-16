#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> arr1, vector<int> arr2) {
    int m = arr1.size();
    int n = arr2.size();

    int low = 0, high = m;
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : arr1[cut1];
        int r2 = cut2 == n ? INT_MAX : arr2[cut2];

        if (l1 <= r2 and l2 <= r1) {
            if ((m + n) % 2 == 0) {
                return (max(l1, l2) + max(r1, r2)) / 2.0;
            } else {
                return max(l1, l2) * 1.0;
            }
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main() {
    vector<int> arr1 = {7, 12, 14, 15, 16};
    vector<int> arr2 = {1, 2, 3, 4, 9, 11};
    cout << findMedianSortedArrays(arr1, arr2);
}