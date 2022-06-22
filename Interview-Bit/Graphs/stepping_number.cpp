
#include <bits/stdc++.h>
using namespace std;

bool isSteppingNumber(int n) {
    string digits = to_string(n);
    int len = digits.size();
    for (int i = 1; i < len; i++) {
        if (abs(digits[i] - digits[i - 1]) != 1) {
            return false;
        }
    }
    return true;
}

vector<int> stepnum(int A, int B) {
    vector<int> result;
    for (int i = A; i <= B; i++) {
        if (isSteppingNumber(i)) result.push_back(i);
    }
    return result;
}

int main() {
    int A = 10;
    int B = 20;
    vector<int> result = stepnum(A, B);
    for (auto x : result) cout << x << ",";
}
