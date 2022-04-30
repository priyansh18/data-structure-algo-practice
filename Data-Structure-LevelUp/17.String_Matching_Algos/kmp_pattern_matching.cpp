#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string pattern) {
    int n = pattern.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 and pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

int kmpSearch(string text, string pattern) {
    // Create Prefix Suffix Table/ Pie Table for pattern to be searched.
    vector<int> pieTable = prefix_function(pattern);

    int pos = -1;
    int i(0), j(0);

    while (i < text.length()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = pieTable[j - 1];
            } else {
                i++;
            }
        }

        if (j == pattern.size()) {
            pos = i - pattern.size();
            break;
        }
    }

    return pos;
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    cout << "Match Found at Index : " << kmpSearch(text, pattern);
}