#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void findingSubsets(string str, string output, vector<string> &v) {
    if (str.size() == 0) {
        v.push_back(output);
        return;
    }

    char ch = str[0];
    string reducedInput = str.substr(1);

    // Include character
    findingSubsets(reducedInput, output + ch, v);
    // Exclude character
    findingSubsets(reducedInput, output, v);
}

int main() {
    string str;
    cin >> str;
    string output = "";
    vector<string> v;
    findingSubsets(str, output, v);

    for (auto x : v) {
        cout << x << ",";
    }
    cout << endl;
}