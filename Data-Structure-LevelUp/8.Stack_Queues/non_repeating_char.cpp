#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    char ch;
    cin >> ch;
    queue<char> q;
    int freq[27] = {0};
    while (ch != '.') {
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty()) {
            int index = q.front() - 'a';
            if (freq[index] > 1) {
                q.pop();
            } else {
                cout << q.front() << endl;
                break;
            }
        }
        if (q.empty()) {
            cout << "-1" << endl;
        }

        cin >> ch;
    }
}