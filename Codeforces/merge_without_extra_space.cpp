#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    int m = arr1.size();
    int n = arr2.size();

    int i = 0;
    int j = 0;

    while (i < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            sort(arr1.begin(), arr1.end());
            sort(arr2.begin(), arr2.end());
            i++;
        }
    }

    for (auto x : arr1) {
        cout << x << ",";
    }

    cout << endl;

    for (auto y : arr2) {
        cout << y << ",";
    }
}

// 1,3,5,7
// 0,2,6,8,9

// 0,3,5,7
// 1,2,6,8,9

// 0,1,5,7
// 2,3,6,8,9

// 0,1,2,3
// 7,5,6,8,9

void merge(int arr1[], int arr2[], int n, int m) {
    int i = 0;
    int j = 0;

    while (i < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
            i++;
        } 
    }
}