#include <iostream>
#include <vector>
using namespace std;

float squareRoot(int n, int p) {
    int start = 0;
    int end = n;
    float ans = 0;
    // Binary Search for integer part
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Linear Search for decimal part
    float inc = 0.1;
    for (int place = 1; place <= p; place++) {
        while (ans * ans <= n) {
            ans += inc;
        }

        ans = ans - inc;
        inc = inc/10.0;
    }

    return ans;
}

int main() {
    int n, p;
    cin >> n >> p;
    cout << squareRoot(n, p) << endl;
}