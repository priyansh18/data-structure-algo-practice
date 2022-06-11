// Kill Process

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        unordered_map<int, list<int>> m;
        vector<int> result;
        for (int i = 0; i < pid.size(); i++) {
            m[ppid[i]].push_back(pid[i]);
        }

        queue<int> q;
        q.push(kill);
        result.push_back(kill);
        while (!q.empty()) {
            /* code */
            int temp = q.front();
            q.pop();
            for (auto nbr : m[temp]) {
                result.push_back(nbr);
                q.push(nbr);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> pid = {1, 3, 10, 5};
    vector<int> ppid = {3, 0, 5, 3};
    int kill = 5;
    vector<int> result = s.killProcess(pid, ppid, kill);
    for (auto x : result) cout << x << ",";
}