#include <bits/stdc++.h>
using namespace std;

bool is_sorted(vector<int> arr, int start, int end) {
    if (start == end) {
        return true;
    }
    if (is_sorted(arr, start + 1, end)) {
        if (arr[start] < arr[start + 1]) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool is_sorted_s(vector<int> arr, int start, int end) {
    if (start == end) {
        return true;
    }

    if (arr[start] > arr[start + 1]) {
        return false;
    } else {
        return is_sorted(arr, start + 1, end);
    }
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 9};
    cout << is_sorted(arr, 0, arr.size() - 1) << endl;
    cout << is_sorted_s(arr, 0, arr.size() - 1) << endl;
}