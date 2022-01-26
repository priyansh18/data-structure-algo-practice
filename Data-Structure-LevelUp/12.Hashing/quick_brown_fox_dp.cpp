#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int minimumSpacesRequired(string str, unordered_set<string> &s, int i) {
    if (str[i] == '\0') {
        return 0;
    }

    int ans = INT8_MAX;
    string current_string = "";

    for (int j = i; str[j] != '\0'; j++) {
        current_string += str[j];

        if (s.find(current_string) != s.end()) {
            int remaining_ans = minimumSpacesRequired(str, s, j + 1);
            if (remaining_ans != -1) {
                ans = min(ans, 1 + remaining_ans);
            }
        }
    }

    if (ans == INT8_MAX) {
        return -1;
    }
    return ans;
}

int main() {
    string str = "thequickbrownfox";
    string words[] = {"the", "quickbrown", "fox", "quick", "brown"};

    unordered_set<string> s;
    for (string st : words) {
        s.insert(st);
    }

    cout << minimumSpacesRequired(str, s, 0) - 1 << endl;
}