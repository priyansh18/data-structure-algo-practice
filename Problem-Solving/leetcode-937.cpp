// Reorder Data in log Files.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static int findForlogs(string str) {
        int j = 0;
        while (j < str.length()) {
            if (str[j] == ' ') {
                break;
            }
            j++;
        }
        j++;

        return j;
    }

    static bool compare(string A, string B) {
        int m = findForlogs(A);
        int n = findForlogs(B);

        if (A.substr(m) != B.substr(n)) {
            return A.substr(m) < B.substr(n);
        } else {
            return A.substr(0, m - 1) < B.substr(0, n - 1);
        }
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result;
        vector<string> letter_logs;
        vector<string> digit_logs;

        for (auto x : logs) {
            int i = findForlogs(x);
            if (x[i] >= '0' and x[i] <= '9') {
                digit_logs.push_back(x);
            } else {
                letter_logs.push_back(x);
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), compare);

        for (auto x : letter_logs) {
            result.push_back(x);
        }

        for (auto x : digit_logs) {
            result.push_back(x);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                           "let2 own kit dig", "let3 art zero"};
    vector<string> result = s.reorderLogFiles(logs);
    for (auto x : result) {
        cout << x << endl;
    }
}