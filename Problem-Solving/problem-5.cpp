// Kth node from the end of linked list.

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void insertionAtTail(Node*& head, int data) {
    if (head == NULL) {
        Node* n = new Node(data);
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* n = new Node(data);
    temp->next = n;
    n->next = NULL;
}

int kthNodeFromEnd(Node* head, int k) {
    Node* temp = head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    int toFind = length - k;

    Node* temp1 = head;
    int count = 0;
    while (count != toFind) {
        temp1 = temp1->next;
        count++;
    }
    return temp1->data;
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << "--->";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insertionAtTail(head, 9);
    insertionAtTail(head, 8);
    insertionAtTail(head, 7);
    insertionAtTail(head, 6);
    insertionAtTail(head, 5);
    printLL(head);
    cout << endl;
    cout << kthNodeFromEnd(head, 4) << endl;
}