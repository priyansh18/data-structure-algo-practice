// Design a stack to obtain minimum elemnent in O(1) time and space.

#include <bits/stdc++.h>
using namespace std;

class MinStack {
   public:
    stack<> s;
    int minEle;
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            minEle = val;
            s.push(val);
            return;
        } else if (val < minEle) {
            s.push(2 * val - minEle);
            minEle = val;
        } else {
            s.push(val);
        }
    }

    void pop() {
        if (s.empty()) {
            return;
        }
        int t = s.top();
        s.pop();

        if (t < minEle) {
            minEle = 2 * minEle - t;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        int t = s.top();  // Top element.

        if (t < minEle) {
            return minEle;
        } else {
            return t;
        }
    }

    int getMin() {
        if (s.empty())
            return -1;
        else
            return minEle;
    }
};

int main() {
    MinStack s;
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(6);
    s.push(-1);
    s.push(7);
    cout << s.getMin() << endl;
    cout << s.top() << endl;
}