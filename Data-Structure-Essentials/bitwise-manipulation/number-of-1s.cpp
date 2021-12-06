#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp = n;
    int count = 0;
    while (temp != 0) {
        // (n & n-1) have all the same bits except rightmost bit which is 1 so
        // no of times procedure repeats calculates no of 1 in number.
        temp = (temp & temp - 1);
        count++;
    }

    cout << "Numbers of Ones in binary representation of " << n << " is "
         << count << endl;
}