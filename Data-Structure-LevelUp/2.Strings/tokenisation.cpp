#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    // Creating a stringstream object
    stringstream ss(input);

    string token;
    vector<string> tokens;

    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    for (auto token : tokens) {
        cout << token << ",";
    }
    cout << endl;

    
}
