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

Node* reverseLinkedListIteratively(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* temp;

    while (temp != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* kReverse(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* temp;

    int count = 1;
    while (curr != NULL and count <= k) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }

    if (temp != NULL) {
        head->next = kReverse(temp, k);
    }

    return prev;
}

Node* reverseLinkedListRecursively(Node* head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }

    Node* smallHead = reverseLinkedListRecursively(head->next);
    head->next->next = head;
    head->next = NULL;

    return smallHead;
}

void insertionAtHead(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return;
    }

    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void insertionAtMiddle(Node*& head, int data, int pos) {
    if (pos == 0) {
        insertionAtHead(head, data);
        return;
    }
    Node* temp = head;
    while (--pos) {
        temp = temp->next;
    }
    Node* n = new Node(data);
    n->next = temp->next;
    temp->next = n;
}

void insertionAtTail(Node* head, int data) {
    if (head == NULL) {
        Node* n = new Node(data);
        head = n;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* n = new Node(data);
    temp->next = n;
    n->next = NULL;
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << "--->";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insertionAtHead(head, 9);
    insertionAtHead(head, 8);
    insertionAtHead(head, 7);
    insertionAtHead(head, 6);
    insertionAtHead(head, 5);
    insertionAtMiddle(head, 10, 2);
    insertionAtMiddle(head, 1, 0);
    printLL(head);
    cout << endl;

    head = kReverse(head, 3);
    printLL(head);

    cout << endl;
    head = reverseLinkedListRecursively(head);
    printLL(head);

    cout << endl;
    head = reverseLinkedListIteratively(head);
    printLL(head);
}