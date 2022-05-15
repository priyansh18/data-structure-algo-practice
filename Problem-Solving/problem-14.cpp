// Minimum Swaps of adjancent for bracket balancing.

#include <bits/stdc++.h>
using namespace std;

int swapsBracket(string str) {
    int n = str.length();
    int countLeft = 0;
    int countRight = 0;
    int imbalance = 0;
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '[') {
            countLeft++;
            if (imbalance > 0) {
                swaps += imbalance;
                imbalance--;
            }
        } else if (str[i] == ']') {
            countRight++;
            imbalance = countRight - countLeft;
        }
    }

    return swaps;
}

int main() {
    string str = "[[][]]";
    cout << swapsBracket(str) << endl;
}