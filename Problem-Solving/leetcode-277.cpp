//  Celebrity Problem

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

bool knows(int a, int b) { return mat[a][b]; }

class Solution {
   public:
    int findCelebrity(int n) {
        stack<int> st;

        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        while (st.size() >= 2) {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();

            if (knows(i, j)) {
                // if i know j then i is not a celebrity.
                st.push(j);
            } else {
                // if i don't know j then j is not a celebrity.
                st.push(i);
            }
        }

        int pot = st.top();
        st.pop();

        for (int i = 0; i < n; i++) {
            if (i != pot) {
                if (!knows(i, pot) or knows(pot, i)) {
                    return -1;
                }
            }
        }

        return pot;
    }
};

int main() {
    Solution s;
    int n = 3;
    cout << s.findCelebrity(n) << endl;
}