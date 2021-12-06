#include <iostream>

// forward declaration
class List;

class Node {
    int data;

   public:
    Node* next;
    Node(int d) : data(d), next(NULL) {}

    int getData() { return data; }
    // To access next pointer
    friend class List;
};

class List {
    Node* head;
    Node* tail;

   public:
    List() : head(NULL), tail(NULL) {}

    Node* begin() { return head; }

    void push_front(int d) {
        if (head == NULL) {
            Node* n = new Node(d);
            head = tail = n;
        } else {
            Node* n = new Node(d);
            n->next = head;
            head = n;
        }
    }

    void push_back(int d) {
        if (head == NULL) {
            Node* n = new Node(d);
            head = tail = n;
        } else {
            Node* n = new Node(d);
            tail->next = n;
            tail = n;
        }
    }

    void insert(int d, int pos) {
        if (pos == 0) {
            push_front(d);
            return;
        }
        Node* n = new Node(d);
        Node* temp = head;
        while (--pos) {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }

    bool search_node(int key) {
        if (head == NULL) {
            return false;
        }
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            } else {
                temp = temp->next;
            }
        }
        return false;
    }

    void pop_front() {
        if (head == NULL) {
            return;
        }
        Node* n = head;
        head = n->next;
        n->next = NULL;
        delete n;
    }

    void pop_back() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* n = temp->next;
        temp->next = NULL;
        delete n;
    }

    void pop_middle(int pos) {
        Node* temp = head;
        while (--pos) {
            temp = temp->next;
        }
        Node* n = temp->next;
        temp->next = n->next;
        n->next = NULL;
        delete n;
    }
};