#include <iostream>

#include "list.h"
using namespace std;


int main() {
    List l;
    l.push_front(0);
    l.push_back(1);
    l.push_back(3);
    l.push_back(4);
    l.insert(2, 2);
    l.insert(5, 5);
    l.insert(-1, 0);


    cout << l.search_node(40) << endl;
    l.pop_front();
    l.pop_front();
    l.pop_back();
    l.pop_middle(2);

    Node* head = l.begin();
    while (head != NULL) {
        cout << head->getData() << "-->";
        head = head->next;
    }


    


}