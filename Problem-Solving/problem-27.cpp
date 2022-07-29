// Permutation with spaces

#include <bits/stdc++.h>
using namespace std;

void helper(string input, string output, vector<string> &res) {
    if (input.size() == 0) {
        res.push_back(output);
        return;
    }
    string ch = "";
    ch += input[0];
    input.erase(input.begin() + 0);
    helper(input, output + '_' + ch, res);
    helper(input, output + ch, res);
}

vector<string> solution(string str) {
    string input = str;
    string output = "";
    output += str[0];
    input.erase(input.begin() + 0);
    vector<string> res;
    helper(input, output, res);
    return res;
}

int main() {
    string str = "ABC";
    vector<string> result = solution(str);
    for (auto x : result) cout << x << endl;
}