#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<long long> &arr, int n, int cows, int dist) {
    int cordinate = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] - cordinate >= dist) {
            count++;
            cordinate = arr[i];
        }
        if (count == cows) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int c;
        cin >> n >> c;
        vector<long long> arr;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        int s = 1;
        int e = arr[n - 1] - arr[0];
        long long ans = 0;
        int mid;

        while (s <= e) {
            mid = (s + e) / 2;
            if (canPlaceCows(arr, n, c, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        cout << ans << endl;
    }
}