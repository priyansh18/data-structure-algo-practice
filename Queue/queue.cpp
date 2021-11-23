#include "queue.h"

#include <iostream>
using namespace std;

int main() {
    Queue que(7);
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    que.pop();
    que.pop();
    que.pop();
    que.push(9);

    while (!que.empty()) {
        cout << que.getFront() << endl;
        que.pop();
    }
}