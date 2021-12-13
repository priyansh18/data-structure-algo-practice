#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestBand(vector<int> arr) {
    // 1. It can also be done using sorting but it will take O(nlogn) for
    // sorting and O(n) in searching so overall complexity would be O(nlogn) but
    // using unordered set we can reduce its complexity to O(n)
    unordered_set<int> s;
    for (int x : arr) {
        s.insert(x);
    }
    int largest = 0;
    for (int i = 0; i < arr.size(); i++) {
        int count = 1;
        if (s.find(arr[i] - 1) != s.end()) {
            continue;
        } else {
            if (s.find(arr[i] + 1) != s.end()) {
                int x = 1;
                while (s.find(arr[i] + x) != s.end()) {
                    count++;
                    x++;
                }
            }
        }
        largest = max(largest, count);
    }

    return largest;
}

int main() {
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longestBand(arr) << endl;
}