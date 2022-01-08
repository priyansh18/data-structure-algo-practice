#include <iostream>
using namespace std;

void housing(int arr[], int n, int k) {
    int i = 0;
    int j = i + 1;
    int current_sum = arr[i];

    while (j < n) {
        if (current_sum == k) {
            cout << i << "----" << j-1 <<endl;
            current_sum -= arr[i];
            i++;
        } else if (current_sum > k) {
            current_sum -= arr[i];
            i++;
        } else {
            current_sum += arr[j];
            j++;
        }
    }
}

int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int k;
    cin >> k;
    housing(arr, n, k);
}