#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int noOfTripletsInGp(vector<int> arr, int r) {
    unordered_map<long, long> left, right;

    // Initializing the right map with frequency of elements

    for (auto x : arr) {
        right[x]++;
        left[x] = 0;
    }
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        right[arr[i]]--;

        if (arr[i] % r == 0) {
            long b = arr[i];
            long a = arr[i] / r;
            long c = arr[i] * r;

            ans += left[a] * right[c];
        }

        left[arr[i]]++;
    }

    return ans;
}

int main() {
    vector<int> arr{1, 16, 4, 16, 64, 16};
    int r = 4;
    cout << noOfTripletsInGp(arr, r) << endl;
}