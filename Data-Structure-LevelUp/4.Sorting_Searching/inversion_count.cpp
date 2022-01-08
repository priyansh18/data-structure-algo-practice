#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int start, int end) {
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;

    vector<int> temp;
    int count = 0;

    while (i <= mid and j <= end) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else if (arr[i] > arr[j]) {
            count += mid - i + 1;
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

    return count;
}

int inversionCount(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return 0;
    }

    int mid = (start + end) / 2;

    int C1 = inversionCount(arr, start, mid);
    int C2 = inversionCount(arr, mid + 1, end);

    int CI = merge(arr, start, end);
    return C1 + C2 + CI;
}

int main() {
    vector<int> arr{10, 24, 6, 1, 79, 20, -1, 30};
    int n = arr.size();
    cout << inversionCount(arr, 0, n - 1) << endl;
}