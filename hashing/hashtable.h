#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
   public:
    string key;
    T value;
    Node* next;

    Node(string key, T value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

template <typename T>
class Hashtable {
    Node<T>** table;
    // Current size filled with values.
    int curr_size;
    // Whole Table Size.
    int tab_size;

    int hashFn(string key) {
        int idx = 0;
        int power = 1;
        for (auto ch : key) {
            idx = (idx + ch * power) % tab_size;
            power = (power * 29) % tab_size;
        }
        return idx;
    }

    void rehash() {
        // Point old table to current table and table to new table
        Node<T>** oldTable = table;
        int oldTs = tab_size;

        curr_size = 0;
        tab_size = 2 * tab_size + 1;
        table = new Node<T>*[tab_size];
        // Initialize every table value to NULL
        for (int i = 0; i < tab_size; i++) {
            table[i] = NULL;
        }
        // Copy Elements from old table to new table
        for (int i = 0; i < oldTs; i++) {
            Node<T>* temp = oldTable[i];
            while (temp != NULL) {
                string key = temp->key;
                T value = temp->value;
                insert(key, value);
                temp = temp->next;
            }
            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

   public:
    Hashtable(int default_size = 12) {
        curr_size = 0;
        tab_size = default_size;
        table = new Node<T>*[tab_size];
        for (int i = 0; i < tab_size; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, T val) {
        int idx = hashFn(key);
        Node<T>* n = new Node<T>(key, val);

        //  Insertion at head
        n->next = table[idx];
        table[idx] = n;
        curr_size++;

        float load_factor = curr_size / float(tab_size);
        if (load_factor > 0.7) {
            rehash();
        }
    }

    T* search(string key) {
        int idx = hashFn(key);
        Node<T>* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return &temp->value;
            }
            temp = temp->next;
        }

        return NULL;
    }

    void erase(string key) {
        int idx = hashFn(key);
        Node<T>* temp = table[idx];
        if (temp == NULL) {
            return;
        }
        if (temp->key == key) {
            Node<T>* b = temp;
            table[idx] = b->next;
            delete b;
        } else {
            while (temp->next != NULL) {
                if (temp->next->key == key) {
                    Node<T>* b = temp->next;
                    temp->next = b->next;
                    delete b;
                } else {
                    temp = temp->next;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < tab_size; i++) {
            cout << "Bucket " << i << "->>>";
            Node<T>* temp = table[i];
            while (temp != NULL) {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};