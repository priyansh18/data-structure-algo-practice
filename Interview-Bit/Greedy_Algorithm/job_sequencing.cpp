#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;      // Job Id
    int dead;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};

bool compare(Job A, Job B) { return A.profit > B.profit; }

class Solution {
   public:
    vector<int> JobScheduling(Job arr[], int n) {
        vector<int> result;
        sort(arr, arr + n, compare);
        vector<int> A(n, -1);
        int profit = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead - 1; j >= 0; j--) {
                if (A[j] == -1) {
                    count++;
                    profit += arr[i].profit;
                    A[j] = 1;
                    break;
                }
            }
        }

        result.push_back(count);
        result.push_back(profit);

        return result;
    }
};

int main() {
    Solution s;
    Job arr[4] = {[1, 4, 20], [ 2, 1, 10 ], [ 3, 1, 40 ], [ 4, 1, 30 ]};
    int n = 4;
    vector<int> result = s.JobScheduling(arr, n);
    for (auto x : result) {
        cout << x << ",";
    }
}