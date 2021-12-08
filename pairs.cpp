#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int sum) {
    // 1. Brute Force Approach Compare Every element with another one --O(n^2)

    // 2. Sorting Elements and for every pair search for next index to be found.
    // In sorting nlogn time occur and in iterating on every element and search
    // for element to pair using binary search nlogn Time Complexity - O(nlogn)

    // 3.Using of Unordered set takes const time in searching and for every
    // element it can be done in O(n) time.
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        int target = sum - arr[i];
        if (s.find(target) != s.end()) {
            result.push_back(target);
            result.push_back(arr[i]);
        } else {
            s.insert(arr[i]);
        }
    }

    return result;
}

int main() {
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int s = 4;
    auto p = pairSum(arr, s);
    if (p.size() == 0) {
        cout << "No Pairs Found";
    } else {
        cout << p[0] << "," << p[1] << endl;
    }
}