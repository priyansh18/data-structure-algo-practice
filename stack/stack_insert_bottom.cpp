#include <iostream>

#include "stackVector.h"
using namespace std;

// Using another stack
void insertAtBottom(Stack<int> &S, int data) {
    Stack<int> R;
    while (!S.empty()) {
        R.push(S.top());
        S.pop();
    }
    S.push(data);
    while (!R.empty()) {
        S.push(R.top());
        R.pop();
    }
}

// Recursively withoout other stack
void insertAtBottomRec(Stack<int> &S, int data) {
    if (S.empty()) {
        S.push(data);
        return;
    }

    int temp = S.top();
    S.pop();
    insertAtBottom(S, data);
    S.push(temp);
}

// Revesrse Stack
void reverse(Stack<int> &S){
  if(S.empty()){
    return;
  }
  int t = S.top();
  S.pop();
  reverse(S);
  insertAtBottomRec(S,t);
}


int main() {
    Stack<int> L;
    L.push(1);
    L.push(3);
    L.push(5);
    L.push(6);
    L.push(9);

    insertAtBottom(L, 0);

    reverse(L);
    
    while (!L.empty()) {
        cout << L.top() << endl;
        L.pop();
    }


    cout << "******************" << endl;

    Stack<int> M;
    M.push(1);
    M.push(3);
    M.push(5);
    M.push(6);
    M.push(9);

    insertAtBottomRec(M, 0);

    while (!M.empty()) {
        cout << M.top() << endl;
        M.pop();
    }
}