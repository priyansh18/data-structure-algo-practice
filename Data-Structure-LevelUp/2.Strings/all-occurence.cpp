#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph =
        "We are learning abiut STL strings.STL string class is quite "
        "powerfull.";

    string word;
    cin >> word;
    int index = paragraph.find(word);
    while (index != -1) {
        cout << index << ",";
        index = paragraph.find(word, index + 1);
    }
}