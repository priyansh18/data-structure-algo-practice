#include <iostream>
using namespace std;

int main() {
    char arr[100];
    cin.getline(arr, 100);

    int x = 0;
    int y = 0;
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] == 'S') {
            y--;
        } else if (arr[i] == 'N') {
            y++;
        } else if (arr[i] == 'W') {
            x--;
        } else if (arr[i] == 'E') {
            x++;
        }
        i++;
    }

    cout << x << "  " << y<<endl;

    while (x--) {
        if (x < 0) {
            cout << "W";
        } else {
            cout << "E";
        }
    }

    while (y--) {
        if (y < 0) {
            cout << "S";
        } else {
            cout << "N";
        }
    }

}