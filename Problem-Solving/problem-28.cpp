//  Letter Case Permutation

#include <bits/stdc++.h>
using namespace std;

void helper(string input, string output, vector<string> &res) {
    if (input.size() == 0) {
        res.push_back(output);
        return;
    }
    char ch = input[0];
    input = input.substr(1);
    if (ch >= 'a' and ch <= 'z') {
        char v = ch - 'a' + 'A';
        helper(input, output + v, res);
        helper(input, output + ch, res);
    } else {
        helper(input, output + ch, res);
    }
}

vector<string> permutations(string str) {
    string input = str;
    string output = "";
    vector<string> res;
    helper(input, output, res);
    return res;
}

int main() {
    string str = "a1b2c3";
    vector<string> result = permutations(str);
    for (auto x : result) cout << x << endl;
}