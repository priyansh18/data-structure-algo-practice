#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


int main() {
    vector<int> arr = {1, 2, 3, 5};
    unordered_set<int> s;
    for (auto x : arr) {
        s.insert(x);
    }

    int i = 1;
    while (i < arr.size()) {
        if (s.find(i) != s.end()) {
            i++;
        } else {
            break;
        }
    }

    cout << i;
}