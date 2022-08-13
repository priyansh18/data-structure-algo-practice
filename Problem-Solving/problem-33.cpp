// XOR Two numbers occurs one time

#include <bits/stdc++.h>
using namespace std;

vector<int> findDifferentNumbers(vector<int> nums) {
    int XORNumber = 0;
    for (auto x : nums) {
        XORNumber ^= x;
    }

    int count = 0;
    while (XORNumber) {
        if (XORNumber & 1) break;
        count++;
        XORNumber = XORNumber >> 1;
    }

    int XOR1 = 0;
    int XOR2 = 0;

    for (auto x : nums) {
        int mask = 1 << count;
        if (x & mask)
            XOR1 ^= x;
        else
            XOR2 ^= x;
    }

    return {XOR1, XOR2};
}

int main() {
    vector<int> nums = {1, 1, 2, 5, 3, 2, 3, 4, 7, 4};
    vector<int> result = findDifferentNumbers(nums);
    cout << result[0] << " and " << result[1] << endl;
}