// Implementation of two stack in using single array.

#include <bits/stdc++.h>
using namespace std;

#define maxSize 100

vector<int> arr(maxSize);
int top1 = -1;
int top2 = maxSize;

void push1(int d) {
    if (top1 < top2 - 1) {
        arr[++top1] = d;
    } else {
        cout << "Stack Overflow";
    }
}

void push2(int d) {
    if (top2 - 1 > top1) {
        arr[--top2] = d;
    } else {
        cout << "Stack Overflow";
    }
}

int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        cout << "Stack Underflow";
    }

    return 0;
}

int pop2() {
    if (top2 <= maxSize - 1) {
        return arr[top2++];
    } else {
        cout << "Stack Underflow";
    }

    return 0;
}

int main() {
    push1(40);
    push1(20);
    push2(10);
    push2(30);
    cout << pop1() << endl;
    cout << pop2() << endl;
}