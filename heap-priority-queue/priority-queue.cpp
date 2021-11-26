#include <iostream>
#include <queue>
using namespace std;

int main() {
    int arr[] = {10, 15, 20, 13, 6, 80};
    int n = sizeof(arr) / sizeof(int);
    // By default STL queue is max-heap
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Max-heap : "
         << " ";
    for (int x : arr) {
        maxHeap.push(x);
    }

    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    cout << "Min-heap : "
         << " ";
    for (int x : arr) {
        minHeap.push(x);
    }

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}