#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int lastOccurence(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int frequencyCount(int arr[], int n, int key) {
    int upper_bound = firstOccurence(arr, n, key);
    int lower_bound = lastOccurence(arr, n, key);

    return lower_bound - upper_bound + 1;
}

int main() {
    int arr[] = {0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 4,
                 4, 4, 4, 4, 4, 4, 4, 5, 6, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << frequencyCount(arr, n, key) << endl;
}