#include <bits/stdc++.h>
using namespace std;

string solve(string A) {
    vector<string> ans;
    istringstream is(A);
    string token;
    while (getline(is, token, ' ')) {
        // token contains words seperated by space
        // use token.size()!=0 to avoid words without anything in it.
        if (token.size() > 0) ans.push_back(token);
    }
    reverse(ans.begin(), ans.end());
    string output = "";
    for (auto x : ans) {
        cout << x << endl;
        output += x;
        output += " ";
    }

    int n = output.size();
    output[n - 1] = '\0';
    return output;
}

int main() {
    string A = "               sky is blue          ";
    cout << solve(A);
}