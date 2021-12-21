#include <cstring>
#include <iostream>
using namespace std;

bool checkSubsets(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int i = 0;
    int j = 0;
    while (i < m) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if (j == n) {
        return true;
    }

    return false;
}

int main() {
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);

    if (checkSubsets(s1, s2)) {
        cout << "Present";
    } else {
        cout << "Absent";
    }
}