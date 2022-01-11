#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int x) {
    if (i == n) {
        if (x == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int include = countSubsets(arr, n, i + 1, x - arr[i]);
    int exclude = countSubsets(arr, n, i + 1, x);

    return include + exclude;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    int x = 6;
    int n = arr.size();
    int i = 0;
    cout << countSubsets(arr, n, i ,x) << endl;
}