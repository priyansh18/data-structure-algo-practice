#include "hashtable.h"

#include <iostream>
using namespace std;

int main() {
    Hashtable<int> h;
    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Kiwi", 140);
    h.insert("Banana", 200);
    h.insert("Chiku", 230);
    h.insert("Litchi", 230);
    h.insert("Papaya", 240);
    h.insert("Dragon", 260);
    h.insert("Orange", 270);
    h.insert("Grapes", 90);
    h.insert("Guavava", 290);
    h.print();

    string fruit;
    cin >> fruit;

    if (h.search(fruit) != NULL) {
        cout << "Price of " << fruit << " is " << *h.search(fruit) << " ";
    } else {
        cout << "Fruit out of stock.";
    }

    h.erase(fruit);
    cout << endl;
    if (h.search(fruit) != NULL) {
        cout << "Price of " << fruit << " is " << *h.search(fruit) << " ";
    } else {
        cout << "Fruit out of stock.";
    }
}