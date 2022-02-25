#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = nums1.size() - nums2.size() - 1;
    int n = nums2.size() - 1;
    int i = nums1.size() - 1;

    while (m >= 0 and n >= 0) {
        if (nums1[m] < nums2[n]) {
            nums1[i--] = nums2[n--];
        } else {
            nums1[i--] = nums1[m--];
        }
    }

    while (m >= 0) {
        nums1[i--] = nums1[m--];
    }
    while (n >= 0) {
        nums1[i--] = nums2[n--];
    }

    for (auto x : nums1) {
        cout << x << ",";
    }
    return 0;
}