#include <iostream>
#include <queue>
using namespace std;

int main() {
    int arr[] = {10, 15, 20, 13, 6, 9};
    int n = sizeof(arr) / sizeof(int);

    // Max heap
    priority_queue<int> heap;

    for (int x : arr) {
        heap.push(x);
    }

    while (!heap.empty()) {
        cout << heap.top() << ",";
        heap.pop();
    }

    cout << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> heap2;

    for (int x : arr) {
        heap2.push(x);
    }

    while (!heap2.empty()) {
        cout << heap2.top() << ",";
        heap2.pop();
    }
}