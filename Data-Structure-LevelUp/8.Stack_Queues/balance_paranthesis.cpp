#include <iostream>
#include <stack>
using namespace std;

bool balanceParanthesis(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        }
        if (str[i] == ')') {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }

    if (s.empty()) {
        return true;
    }

    return false;
}

int main() {
    string str = "((a+b)*x-d))";
    if (balanceParanthesis(str)) {
        cout << "True";
    } else {
        cout << "False";
    }
}