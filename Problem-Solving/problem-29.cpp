// Print N-bit binary numbers having more 1’s than 0’s in all prefixes

#include <bits/stdc++.h>
using namespace std;

void helper(int n, int ones, int zeroes, string output,
            vector<string> &result) {
    if (n == 0) {
        result.push_back(output);
        return;
    }

    if (ones > zeroes) {
        helper(n - 1, ones + 1, zeroes, output + '1', result);
        helper(n - 1, ones, zeroes + 1, output + '0', result);
    }
    if (ones == zeroes) {
        helper(n - 1, ones + 1, zeroes, output + '1', result);
    }
}

vector<string> prefixString(int n) {
    string output = "";
    output += '1';
    int ones = 1;
    int zeroes = 0;
    vector<string> result;
    helper(n - 1, ones, zeroes, output, result);
    return result;
}

int main() {
    int n = 6;
    vector<string> result = prefixString(n);
    for (auto x : result) cout << x << endl;
}