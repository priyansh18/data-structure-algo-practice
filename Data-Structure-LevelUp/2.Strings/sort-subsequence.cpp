#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void sortSubsequence(string s, string output, vector<string> &v) {
    // Base case
    if (s.size() == 0) {
        v.push_back(output);
        return;
    }

    char ch = s[0];
    string reduced_input = s.substr(1);
    // Includes
    sortSubsequence(reduced_input, output + ch, v);
    // Excludes
    sortSubsequence(reduced_input, output, v);
}

bool compare(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main() {
    string s1;
    cin >> s1;
    vector<string> v;
    string output = "";
    sortSubsequence(s1, output, v);

    sort(v.begin(), v.end(), compare);

    for (auto x : v) {
        cout << x << ",";
    }
    cout << endl;
}