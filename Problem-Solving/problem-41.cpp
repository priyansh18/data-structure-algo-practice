//  Eating Fish

#include <bits/stdc++.h>
using namespace std;
vector<int> result;
vector<int> fishes = {10, 11, 8, 5, 3, 4, 6, 9, 2, 1, 7};
vector<int> direction = {-1, -1, 1, 1, 1, -1, -1, -1, -1, -1, 1};

void remainingFishes() {
    stack<int> st;
    int n = fishes.size();

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(i);
        } else {
            if (direction[st.top()] > 0 and direction[i] < 0) {
                while (!st.empty() and direction[st.top()] > 0 and direction[i] < 0) {
                    if (fishes[st.top()] < fishes[i]) {
                        st.pop();
                    } else {
                        break;
                    }
                }
                st.push(i);
            } else {
                st.push(i);
            }
        }
    }


    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());
}

void solve() {
    remainingFishes();
    for (auto x : result) {
        cout << x << ",";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
}