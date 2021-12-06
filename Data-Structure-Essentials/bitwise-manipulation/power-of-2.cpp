#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "No,Number is not a Power of 2" << endl;
    } else {
        if ((n & n - 1) == 0) {
            cout << "Yes Number is Power of 2" << endl;
        } else {
            cout << "No,Number is not a Power of 2" << endl;
        }
    }
}