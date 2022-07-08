#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        return -1;

    int n = gas.size();
    int remaining_fuel = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        remaining_fuel += gas[i] - cost[i];
        if (remaining_fuel < 0) {
            start = i + 1;
            remaining_fuel = 0;
        }
    }

    return start;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(A, B) << endl;
}