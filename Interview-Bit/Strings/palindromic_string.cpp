#include <bits/stdc++.h>
using namespace std;

void filterString(string &A) {
    int n = A.length();
    string output = "";
    for (int i = 0; i < n; i++) {
        if (A[i] >= 'A' and A[i] <= 'Z') {
            output += tolower(A[i]);
        } else if (A[i] >= 'a' and A[i] <= 'z') {
            output += A[i];
        } else if (A[i] >= '0' and A[i] <= '9') {
            output += A[i];
        }
    }

    A = output;
}

int isPalindrome(string A) {
    filterString(A);
    
    int s = 0;
    int e = A.length() - 1;

    while (s < e) {
        if (A[s] == A[e]) {
            s++;
            e--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string A = "A man, a plan, a canal: Panama";
    string B = "1a2";
    cout << isPalindrome(B);
}