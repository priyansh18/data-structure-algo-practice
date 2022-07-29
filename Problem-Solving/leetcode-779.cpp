#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isTerminal;
    TrieNode *v[26];
    TrieNode() {
        isTerminal = false;
        for(int i = 0; i<26; i++)
            v[i] = NULL;
    }
  
}*root;

bool inserttt(string s) {
    TrieNode *tmp = root;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int val = s[i] - 'a';
        if(i == (n-1) && tmp->v[val] != NULL) return false;
        if(tmp->v[val] == NULL) tmp->v[val] = new TrieNode();
        tmp = tmp->v[val];
        if(tmp->isTerminal) return false;
    }
    tmp->isTerminal = true;
    return true;
}

string ans, bAns;

string solution(int n, vector<string> arr) {
    bool done = true;
    root = new TrieNode();
    for(i = 0; i<n; i++) {
        string tmp = arr[i];
        if(!done) continue;
        done = inserttt(tmp);
        if(!done)
            bAns = mtp;
    }

    if(done)
        printf("GOOD SET\n");
    else
    {
        printf("BAD SET\n");
        cout << bAns << endl;
    }
}
