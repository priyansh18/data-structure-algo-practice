// Find Running median in data stream

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
   public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;

    MedianFinder() {}

    void addNum(int num) {
        // Initial Case
        if (maxHeap.empty() and minHeap.empty()) {
            minHeap.push(num);
            median = num;
        } else {
            // If maxHeap Size is greater than minHeap
            if (maxHeap.size() > minHeap.size()) {
                if (num < median) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                } else {
                    minHeap.push(num);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;

            }
            // If maxHeap Size is equal to minHeap
            else if (maxHeap.size() == minHeap.size()) {
                if (num < median) {
                    maxHeap.push(num);
                    median = maxHeap.top();
                } else {
                    minHeap.push(num);
                    median = minHeap.top();
                }
            }
            // If maxHeap Size is smaller than minHeap
            else {
                if (num < median) {
                    maxHeap.push(num);
                } else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                }

                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
    }

    double findMedian() { return median; }
};
