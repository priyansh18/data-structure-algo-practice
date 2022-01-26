#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void allSubstring(string s, string output, vector<string> &subs) {
    if (s.size() == 0) {
        subs.push_back(output);
        return;
    }

    char ch = s[0];
    string reduced_input = s.substr(1);

    // Include characters
    allSubstring(reduced_input, output + ch, subs);

    // Exclude characters
    allSubstring(reduced_input, output, subs);
}

bool isVectorEqual(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < 26; i++) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

void filluphashmap(unordered_map<string, vector<int>> &m, string str) {
    vector<int> val(26, 0);
    for (auto x : str) {
        int idx = x - 'a';
        val[idx]++;
    }
    m[str] = val;
}

void anagram_pairs_substring(string str) {
    vector<string> subs;
    string output = "";
    allSubstring(str, output, subs);
    cout << subs.size() << endl;
    unordered_map<string, vector<int>> m;
    for (auto x : subs) {
        if (x != " ") filluphashmap(m, x);
    }

    for (auto p : m) {
        cout << p.first << "->";
        for (auto x : p.second) {
            cout << x << ",";
        }
        cout << endl;
    }

    for (auto p : m) {
        string s = p.first;
        vector<int> sv = p.second;
        for (auto sp : m) {
            string ss = sp.first;
            vector<int> ssv = sp.second;
            if(s!=ss){
              if(isVectorEqual(sv, ssv)) {
                // for(auto x: s) cout<<x<<" ";
                // cout<<endl;
                cout<<s<<" "<<ss<<endl;
              }
            }
        }
    }

}

int main() {
    string str = "abba";
    anagram_pairs_substring(str);
}