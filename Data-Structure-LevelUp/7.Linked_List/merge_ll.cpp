#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        next = NULL;
    }
};

void insertionAtHead(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return;
    }

    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << "--->";
        head = head->next;
    }
}

Node* mergeLL(Node* a, Node* b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    Node* c;
    if (a->data < b->data) {
        c = a;
        c->next = mergeLL(a->next, b);
    } else {
        c = b;
        c->next = mergeLL(a, b->next);
    }

    return c;
}

int main() {
    Node* A = NULL;

    insertionAtHead(A, 10);
    insertionAtHead(A, 7);
    insertionAtHead(A, 5);
    insertionAtHead(A, 1);

    printLL(A);

    cout << endl;

    Node* B = NULL;
    insertionAtHead(B, 6);
    insertionAtHead(B, 3);
    insertionAtHead(B, 2);
    printLL(B);

    cout << endl;


    Node* head = mergeLL(A, B);

    printLL(head);
}