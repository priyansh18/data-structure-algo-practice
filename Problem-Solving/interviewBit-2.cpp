// Merge K Sorted Arrays.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> merge(vector<int> temp1, vector<int> temp2) {
        vector<int> result;
        int m = temp1.size();
        int n = temp2.size();
        int i = 0;
        int j = 0;
        while (i < m and j < n) {
            temp1[i] <= temp2[j] ? result.push_back(temp1[i++])
                                 : result.push_back(temp2[j++]);
        }

        while (i < m) result.push_back(temp1[i++]);
        while (j < n) result.push_back(temp2[j++]);

        return result;
    }

    vector<int> mergeSortedArrays(vector<vector<int>> arr) {
        queue<vector<int>> q;
        for (auto x : arr) {
            q.push(x);
        }
        while (q.size() > 1) {
            vector<int> temp1 = q.front();
            q.pop();
            vector<int> temp2 = q.front();
            q.pop();
            vector<int> res = merge(temp1, temp2);
            for (auto x : res) {
                cout << x << ",";
            }
            cout << endl;
            q.push(res);
        }

        return q.front();
    }
};

class ValPair {
   public:
    int val;
    int x;
    int y;

    ValPair(int val, int x, int y) {
        this->val = val;
        this->x = x;
        this->y = y;
    }
};

class Compare {
   public:
    bool operator()(ValPair A, ValPair B) { return A.val > B.val; }
};

class Solution2 {
   public:
    vector<int> mergeSortedArrays(vector<vector<int>> arr) {
        priority_queue<ValPair, vector<ValPair>, Compare> q;
        int m = arr.size();
        int n = arr[0].size();

        for (int i = 0; i < m; i++) {
            q.push(ValPair(arr[i][0], i, 0));
        }
        vector<int> result;
        while (!q.empty()) {
            auto temp = q.top();
            q.pop();
            if (temp.y < arr[temp.x].size()) {
                result.push_back(temp.val);
                temp.y++;
                q.push(ValPair(arr[temp.x][temp.y], temp.x, temp.y));
            }
        }

        return result;
    }
};

int main() {
    Solution2 s;
    vector<vector<int>> arr = {{1, 2, 3, 5}, {2, 4, 6}, {0, 9, 10}};
    vector<int> result = s.mergeSortedArrays(arr);
    for (auto x : result) {
        cout << x << ",";
    }
}   