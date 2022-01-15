#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void maxSubarrayK(vector<int> arr, int k) {
    int n = arr.size();
    deque<int> Q(k);
    int i;
    // Processing the first K elements
    for (i = 0; i < k; i++) {
        while (!Q.empty() and arr[i] > arr[Q.back()]) {
            Q.pop_back();
        }

        Q.push_back(i);
    }
    // Processing remaining elements
    for (; i < n; i++) {
        cout << arr[Q.front()] << ",";
        // Remove elements from the left
        while (!Q.empty() and Q.front() <= i - k) {
            Q.pop_front();
        }
        while (!Q.empty() and arr[i] >= arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
}

int main() {
    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 5};
    int k;
    cin >> k;
    maxSubarrayK(arr, k);
}