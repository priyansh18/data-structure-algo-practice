// Longest Happy String

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string output = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            int n = output.length();
            if (n >= 2 and output[n - 1] == f.second and
                output[n - 2] == f.second) {
                if (pq.empty()) return output;
                auto g = pq.top();
                pq.pop();
                output += g.second;
                g.first--;
                if (g.first) pq.push({g.first, g.second});
                pq.push({f.first, f.second});
                continue;
            }
            output += f.second;
            f.first--;
            if (f.first) pq.push({f.first, f.second});
        }
        return output;
    }
};

int main() {
    Solution s;
    int a = 1;
    int b = 1;
    int c = 7;
    cout << s.longestDiverseString(a, b, c);
}