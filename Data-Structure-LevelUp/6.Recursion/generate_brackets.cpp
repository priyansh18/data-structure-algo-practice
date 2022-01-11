#include <iostream>
using namespace std;

void generateBrackets(string output, int n, int open, int close, int index) {
    if (index == 2 * n) {
        cout << output << endl;
        return;
    }

    if (open < n) {
        generateBrackets(output + '(', n, open + 1, close, index + 1);
    }

    if (close < open) {
        generateBrackets(output + ')', n, open, close + 1, index + 1);
    }
}

int main() {
    string output;
    int n;
    cin >> n;
    generateBrackets(output, n, 0, 0, 0);
}