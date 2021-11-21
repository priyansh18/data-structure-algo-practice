#include "stackLL.h"

#include <iostream>
using namespace std;

int main() {
    Stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;

    Stack<char> C;
    C.push('P');
    C.push('R');
    C.push('I');
    C.push('Y');
    C.push('A');
    C.push('N');
    C.push('S');
    C.push('H');
    while (!C.empty()) {
        cout << C.top() << " ";
        C.pop();
    }
}