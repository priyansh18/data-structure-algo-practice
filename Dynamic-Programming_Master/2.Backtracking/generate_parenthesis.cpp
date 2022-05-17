#include <bits/stdc++.h>
using namespace std;

void generateParenthesisHelper(vector<string> &result, string output,
                               int opening, int closing, int n) {
    if (output.length() == 2 * n) {
        result.push_back(output);
        return;
    }

    if (opening < n) {
        generateParenthesisHelper(result, output + "(", opening + 1, closing,
                                  n);
    }
    if (closing < opening) {
        generateParenthesisHelper(result, output + ")", opening, closing + 1,
                                  n);
    }
}


vector<string> generateParenthesis(int n) {
    string output = "(";
    vector<string> result;
    generateParenthesisHelper(result, output, 1, 0, n);
    return result;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (auto x : result) {
        cout << x << ",";
    }
}