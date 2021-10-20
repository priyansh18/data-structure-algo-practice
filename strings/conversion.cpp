#include <iostream>
using namespace std;

int main() {
    string str = "asdfegrtntbwrFgrbvdc";

    // Conversion from lower to upper
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }

    cout << str;

    // Conversion from upper to lower
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }

    cout << str;
}