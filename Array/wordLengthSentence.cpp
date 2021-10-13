#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[n + 1];

    cin.getline(arr, n);

    int i = 0;
    int currLength = 0, maxLength = 0;
    while (true) {
        if (arr[i] == ' ' || arr[i] == '\0') {
            if (currLength > maxLength) {
                currLength = maxLength;
            } 
                currLength = 0;
        } else {
            currLength++;
        }
        if (arr[i] == '\0') {
            break;
        }

        i++;
    }
    cout << maxLength;
}
