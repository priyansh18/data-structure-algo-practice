#include <iostream>
#include <vector>
using namespace std;

int highestPeakSize(vector<int> arr) {
    int largest = 0;
    for (int i = 1; i < arr.size() - 1;) {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
            int count = 1;
            // Count Backwards
            int j = i;
            while (j >= 1 and arr[j] > arr[j - 1]) {
                j--;
                count++;
            }
            // Count Forwards
            while (i < (arr.size() - 1) and arr[i] > arr[i + 1]) {
                i++;
                count++;
            }
            largest = max(largest, count);
        } else {
            i++;
        }
    }
    return largest;
}

int main() {
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highestPeakSize(arr) << endl;
}