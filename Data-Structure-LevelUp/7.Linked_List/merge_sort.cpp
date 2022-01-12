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

Node* midPoint(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* l) {
    if (l == NULL or l->next == NULL) {
        return l;
    }

    Node* mid = midPoint(l);
    Node* a = l;
    Node* b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return mergeLL(a, b);
}

int main() {
    Node* A = NULL;

    insertionAtHead(A, 10);
    insertionAtHead(A, 35);
    insertionAtHead(A, 50);
    insertionAtHead(A, 0);
    insertionAtHead(A, 2);
    insertionAtHead(A, 7);
    insertionAtHead(A, 5);
    insertionAtHead(A, 1);

    Node* head = mergeSort(A);

    printLL(head);

    cout << endl;
}