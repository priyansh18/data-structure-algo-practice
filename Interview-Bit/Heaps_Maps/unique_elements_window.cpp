#include <bits/stdc++.h>
using namespace std;



vector<int> dNums(vector<int> &A, int B) {
    auto n = A.size();
    vector<int> res;
    //if (B>n)              // This check will also work
    //    return res;
    assert(B<=n);   // if false then write a error message to stdout & calls abort
    
    unordered_map<int, int> m;
    for (auto i = 0; i<n; ++i)
    {
        ++m[A[i]];
        
        if (i-B+1>=0)
        {
            res.emplace_back(m.size());
            --m[A[i-B+1]];
            if (m[A[i-B+1]] == 0)
                m.erase(A[i-B+1]);
        }
    }
    return res;
}

int main() {
    vector<int> A = {1, 2, 1, 3, 4, 3};
    int B = 3;
    vector<int> result = dNums(A, B);
    for (auto x : result) {
        cout << x << ",";
    }
}