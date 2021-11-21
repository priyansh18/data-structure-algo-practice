#include "stackVector.h"
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
    
}