// Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;

#define Pair pair<double, vector<int>>

double fractionalKnapsackProfit(vector<vector<int>> nums, double weight) {
    priority_queue<Pair, vector<Pair>> maxHeap;
    for (auto x : nums) {
        maxHeap.push({x[0] / x[1], x});
    }

    double maxProfit = 0;
    while (weight >= 0) {
        auto valPair = maxHeap.top();
        maxHeap.pop();
        if (weight - valPair.second[1] >= 0) {
            weight -= valPair.second[1];
            maxProfit += valPair.second[0];
        } else {
            maxProfit += (weight / valPair.second[1]) * valPair.second[0];
            weight -= valPair.second[1];
        }
    }

    return maxProfit;
}

int main() {
    int weight = 50;
    vector<vector<int>> nums = {{60, 10}, {100, 20}, {120, 30}};
    cout << fractionalKnapsackProfit(nums, weight) << endl;
}