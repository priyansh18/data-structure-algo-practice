#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);

    return i + 1;
}

int quickSelect(vector<int> arr, int start, int end, int k) {
    int p = partition(arr, start, end);
    if (p == k) {
        return arr[p];
    } else if (p < k) {
        return quickSelect(arr, p + 1, end, k);
    } else {
        return quickSelect(arr, start, p - 1, k);
    }
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main() {
    vector<int> arr{10, 24, 6, 1, 79, 20, -1, 30};
    int n = arr.size();
    int k = 5;

    cout << quickSelect(arr, 0, n - 1, k) << endl;

    quickSort(arr, 0, n - 1);

    for (int x : arr) {
        cout << x << ",";
    }
    cout << endl;
}