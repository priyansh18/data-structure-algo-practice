#include <bits/stdc++.h>
using namespace std;

int noOfFamilyLogins(vector<string> logins) {
    map<string, int> st;
    for (auto x : logins) {
        st[x]++;
    }
    int ways = 0;
    for (auto x : logins) {
        string str = x;
        string newWord = "";
        for (int i = 0; i < str.length(); i++) {
            newWord += str[i] + 1;
        }
        if (st.find(newWord) != st.end()) {
            ways += st[newWord];
        }
    }

    return ways;
}

int main() {
    vector<string> logins = {"bag", "sfe", "cbh", "cbh", "red"};
    cout << noOfFamilyLogins(logins);
}