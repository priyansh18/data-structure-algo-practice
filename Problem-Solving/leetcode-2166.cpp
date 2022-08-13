// Design Bitset
#include <bits/stdc++.h>
using namespace std;

class Bitset {
   public:
    vector<int> bitValue;
    Bitset(int size) { bitValue = vector<int>(size, 0); }

    void fix(int idx) { bitValue[idx] = 1; }

    void unfix(int idx) { bitValue[idx] = 0; }

    void flip() {
        for (int i = 0; i < bitValue.size(); i++) {
            if (bitValue[i] == 0)
                bitValue[i] = 1;
            else
                bitValue[i] = 0;
        }
    }

    bool all() {
        for (int i = 0; i < bitValue.size(); i++) {
            if (bitValue[i] == 0) return false;
        }
        return true;
    }

    bool one() {
        for (int i = 0; i < bitValue.size(); i++) {
            if (bitValue[i] == 1) return true;
        }
        return false;
    }

    int count() {
        int count = 0;
        for (int i = 0; i < bitValue.size(); i++) {
            if (bitValue[i] == 1) count++;
        }
        return count;
    }

    string toString() {
        string s = "";
        for (int i = 0; i < bitValue.size(); i++) {
            s += bitValue[i] + '0';
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

class Bitset {
   public:
    string s;
    Bitset(int size) {
        while (size--) {
            s += '0';
        }
    }

    void fix(int idx) {
        int n = s.length();
        idx = n - idx;
        int mask = 1 << idx;
        return stoi(s) | mask;
    }

    void unfix(int idx) {
        int n = s.length();
        idx = n - idx;
        int mask = 1 << idx;
        return stoi(s) | ~(mask);
    }

    void flip() { return stoi(s) ^ 0 ^ 1; }

    bool all() {
        int n = s.length();
        return _builtin_popcount(stoi(s)) == n;
    }

    bool one() { return _builtin_popcount(stoi(s)) >= 1; }

    int count(){return _builtin_popcount(stoi(s))}

    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */