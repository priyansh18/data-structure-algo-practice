#include <iostream>
#include <stack>
using namespace std;

bool redundantParanthesis(string str) {
    stack<char> s;

    for (auto ch : str) {
        if (ch == ')') {
            bool gotOp = false;
            while (s.top() != '(') {
                if (s.top() == '+' or s.top() == '*' or s.top() == '/' or
                    s.top() == '-') {
                    gotOp = true;
                }
                s.pop();
            }
            s.pop();
            if (gotOp) {
                continue;
            } else {
                return true;
            }
        } else {
            s.push(ch);
        }
    }

    return false;
}

int main() {
    string str = "((a+b))";
    string str2 = "((a+b)+c)";

    if (redundantParanthesis(str)) {
        cout << "Redundant";
    } else {
        cout << "Not Redundant";
    }
    cout << endl;

    if (redundantParanthesis(str2)) {
        cout << "Redundant";

    } else {
        cout << "Not Redundant";
    }
}