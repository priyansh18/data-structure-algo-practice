#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b >= 0 and b <= a) {
            cout << b;
        } else if (b > a) {
            int count = -1;
            while (b > a) {
                count++;
                b--;
            }
            cout << count%(a+1);
        }
        cout << endl;
    }
}