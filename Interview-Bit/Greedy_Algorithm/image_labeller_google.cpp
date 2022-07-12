#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        int x;
        int y;
        cin >> x >> y;

        vector<int> arr;
        for (int i = 0; i < x; i++) {
            int b;
            cin >> b;
            arr.push_back(b);
            
        }

        sort(arr.begin(), arr.end(), greater<int>());

        double ans = 0;
        int i = 0;
        for (; i < y - 1; i++) ans += arr[i];

        // remaning mediam
        vector<int> tmp;
        for (; i < x; i++) tmp.push_back(arr[i]);
        int sz = tmp.size();
        if (sz & 1) {
            ans += tmp[sz / 2];
        } else {
            ans += (tmp[sz / 2] + tmp[(sz / 2) - 1]) / 2.0;
        }

        cout << "Case #" << j << ": ";
        cout << ans << endl;
    }
}