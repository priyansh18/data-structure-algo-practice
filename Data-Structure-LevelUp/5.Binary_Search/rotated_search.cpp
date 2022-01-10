#include <iostream>
#include <vector>
using namespace std;

int rotatedBinarySearch(vector<int> arr, int key) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else {
            // Check if Mid lies on left line
            if (arr[start] <= arr[mid]) {
                if (key >= arr[start] and key <= arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (key >= arr[mid] and key <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // Check if Mid lies on right line
        }
    }

    return -1;
}

int main() {
    vector<int> arr{4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;
    cout << rotatedBinarySearch(arr, key) << endl;
}
