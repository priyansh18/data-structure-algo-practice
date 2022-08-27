#include <bits/stdc++.h>
using namespace std;

int n;

void generateParenthesis(int open, int close, string output) {
    if (output.size() == n) {
        cout << output << endl;
        return;
    }
    if (open < (n / 2)) {
        generateParenthesis(open + 1, close, output + '(');
    }
    if (close < open) {
        generateParenthesis(open, close + 1, output + ')');
    }
}

int main() {
    cin >> n;
    int close = 0;
    int open = 1;
    string output = "(";
    generateParenthesis(open, close, output);
}