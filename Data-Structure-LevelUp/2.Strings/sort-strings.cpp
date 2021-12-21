#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

string extractStringKey(string str, int key) {
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1) {
        s = strtok(NULL, " ");
        key--;
    }
    return string(s);
}
bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}

int convertToInt(string s) {
    int ans = 0;
    int p = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        ans = ((s[i] - '0') * p);
        p = p * 10;
    }

    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

int main() {
    int t;
    cin >> t;
    // For Taking the input from next line. 
    cin.get();
    string temp;
    vector<string> v;
    for (int i = 0; i < t; i++) {
        getline(cin, temp);
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;
    // To Extract keys for comparision and sort them.
    vector<pair<string, string>> vp;
    for (int i = 0; i < t; i++) {
        vp.push_back({v[i], extractStringKey(v[i], key)});
    }

    if (ordering == "numeric") {
        sort(vp.begin(), vp.end(), numericCompare);
    } else {
        sort(vp.begin(), vp.end(), lexicoCompare);
    }

    if (reversal == "true") {
        reverse(vp.begin(), vp.end());
    }

    for (int i = 0; i < t; i++) {
        cout << vp[i].first << endl;
    }
}