#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;

    void heapify(int i) {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        int minIdx = i;

        if (leftChild < v.size() and v[leftChild] < v[i]) {
            minIdx = leftChild;
        }
        if (rightChild < v.size() and v[rightChild] < v[i]) {
            minIdx = rightChild;
        }

        if (minIdx != i) {
            swap(v[i], v[minIdx]);
            heapify(minIdx);
        }
    }

   public:
    Heap(int default_size = 10) {
        v.reserve(default_size + 1);
        v.push_back(-1);
    }

    void push(int data) {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 and v[idx] < v[parent]) {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    // Return Min Element
    int top() { return v[1]; }
    // Remove Min Element
    void pop() {
        // Swap First and Last Element
        int idx = v.size() - 1;
        swap(v[1], v[idx]);
        // Remove last element
        v.pop_back();
        // Pass Index to heapify for min-heap
        heapify(1);
    }

    bool isEmpty() { return v.size() == 1; }
};

int main() {
  Heap h;
  h.push(10);
  h.push(40);
  h.push(2);
  h.push(100);
  h.push(1);
  h.push(11);
  h.pop();

  while(!h.isEmpty()){
    cout<<h.top()<<" ";
    h.pop();
  }
}