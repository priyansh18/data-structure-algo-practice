// Peter and a combination lock

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    //  2^n == 1<<n
    bool flag = false;
    for (int i = 0; i < (1 << n) - 1; i++) {
        int sum = 0;
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit))
                sum += nums[bit];
            else
                sum -= nums[bit];
        }

        if (sum % 360 == 0) {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "YES"<<endl;
    else
        cout << "No"<<endl;

    return 0;
}