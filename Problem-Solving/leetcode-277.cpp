//  Celebrity Problem

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

// bool knows(int a, int b) { return mat[a][b]; }

// class Solution {
//    public:
//     int findCelebrity(int n) {
//         stack<int> st;

//         for (int i = 0; i < n; i++) {
//             st.push(i);
//         }

//         while (st.size() >= 2) {
//             int i = st.top();
//             st.pop();
//             int j = st.top();
//             st.pop();

//             if (knows(i, j)) {
//                 // if i know j then i is not a celebrity.
//                 st.push(j);
//             } else {
//                 // if i don't know j then j is not a celebrity.
//                 st.push(i);
//             }
//         }

//         int pot = st.top();
//         st.pop();

//         for (int i = 0; i < n; i++) {
//             if (i != pot) {
//                 if (!knows(i, pot) or knows(pot, i)) {
//                     return -1;
//                 }
//             }
//         }

//         return pot;
//     }
// };

class {
   public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) {
        // code here
        int i = 0;
        int j = n - 1;
        while (i < j) {
            // i knows j which means i cannot be the celebrity
            if (M[i][j] == 1) {
                i++;
            } else if (M[j][i] == 1) {
                j--;
            } else {
                i++;
                j--;
            }
        }

        // I is currently pointing to our celebrity
        for (int k = 0; k < n; k++) {
            // If celebrity knows other.
            if (M[i][k] == 1) return -1;
            // if anyone don't know celebrity
            if (i != k and M[k][i] == 0) return -1;
        }

        return i;
    }
};

int main() {
    Solution s;
    int n = 3;
    cout << s.findCelebrity(n) << endl;
}