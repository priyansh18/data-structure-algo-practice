#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum) {
    // 1. For Creating Triplets in Brute Force three loops are required so time
    // complexity would be O(n^3)

    // Sorting array require O(nlogn) time and for every element using pair sum
    // method or 2 pointer approach use O(n^2) time so overall time complexity
    // would be O(n^2)
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for (int i = 0; i <= arr.size() - 3; i++) {
        int j = i + 1;
        int k = arr.size() - 1;
        while (j < k) {
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];
            if (currentSum == sum) {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            } else if (currentSum > sum) {
                k--;
            } else {
                j++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;
    auto result = triplets(arr, sum);

    for (auto v : result) {
        for (auto no : v) {
            cout << no << ",";
        }
        cout << endl;
    }
}