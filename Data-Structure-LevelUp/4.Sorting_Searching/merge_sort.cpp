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
        } else if (arr[i] > arr[j]) {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    int k = 0;

    for (int idx = start; idx <= end; idx++) {
        arr[idx] = temp[k++];
    }

    return;
}

void mergeSort(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    return merge(arr, start, end);
}

int main() {
    vector<int> arr{10, 24, 6, 1, 79, 20, -1, 30};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (int x : arr) {
        cout << x << ",";
    }

    cout << endl;
}