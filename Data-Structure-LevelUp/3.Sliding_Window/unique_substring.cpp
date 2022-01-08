#include <iostream>
#include <unordered_map>
using namespace std;

string uniqueSubstring(string str) {
    int i = 0;
    int j = 0;
    int window_length = 0;
    int max_window_length = 0;
    int start_window = -1;
    unordered_map<char, int> s;
    int n = str.length();

    while (j < n) {
        char ch = str[j];
        if (s.count(ch) and s[ch] >= i) {
            i = s[ch] + 1;
            window_length = j - i;  // updated remaining window length excluding current character
        }
        // Update the last occurence.
        s[ch] = j;
        window_length++;
        j++;

        if (window_length > max_window_length) {
            max_window_length = window_length;
            start_window = i;
        }
    }
    return str.substr(start_window, max_window_length);
}

int main() {
    string str = "priyanshsinghal";
    cout << uniqueSubstring(str);
}