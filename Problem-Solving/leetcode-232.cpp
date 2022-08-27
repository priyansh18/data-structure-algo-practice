// Implement Queue using stack

#include <bits/stdc++.h>
using namespace std;

// O(N) for time complexity and O(2N) for space complexity

class MyQueue {
   public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;
        int y = s1.top();
        s1.pop();
        return y;
    }

    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool empty() { return s1.empty(); }
};

// O(1) Amortized time and space complexity

class MyQueue {
   public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if (s2.empty() and s1.empty()) return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int y = s2.top();
        s2.pop();
        return y;
    }

    int peek() {
        if (s2.empty() and s1.empty()) return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int y = s2.top();
        s2.pop();
        return y;
    }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */