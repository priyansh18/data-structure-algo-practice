#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end) {
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;

    vector<int> temp;

    while (i <= mid and j <= end) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for (int i = start; i <= end; i++) {
        arr[i] = temp[k++];
    }

    return;
}

void mergeSort(vector<int> &arr, int start, int end) {
    // Base Case
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    return merge(arr, start, end);
}

int main() {
    vector<int> arr{1, 10, 24, 5, 0, 9, 2};
    int start = 0;
    int end = arr.size() - 1;
    mergeSort(arr, start, end);
    for (int x : arr) {
        cout << x << ",";
    }
}
