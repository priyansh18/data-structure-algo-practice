#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
    int n = A.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == ' ') {
            int j = i;
            while (A[j] == ' ') {
                j++;
            }
            if (j != n) count = 0;
        } else {
            count++;
        }
    }
    return count;
}

int main() {
    string str = "Hello world";
    cout << lengthOfLastWord(str);
}