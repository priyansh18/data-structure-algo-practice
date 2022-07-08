#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int penalty(int h, int w, vector<int> &horizontal, vector<int> &vertical) {
    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());
    int n = horizontal.size();

    int maxH = INT_MIN;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            maxH = max(maxH, horizontal[i] - 1);
        } else if (i == n) {
            maxH = max(maxH, h - horizontal[i - 1] - 1);
        } else {
            maxH = max(maxH, horizontal[i] - horizontal[i - 1] - 1);
        }
    }

    int maxV = INT_MIN;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            maxV = max(maxV, vertical[i] - 1);
        } else if (i == n) {
            maxV = max(maxV, w - vertical[i - 1] - 1);
        } else {
            maxV = max(maxV, vertical[i] - vertical[i - 1] - 1);
        }
    }

    return maxH * maxV;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        int w;
        int n;
        cin >> h >> w >> n;
        vector<int> horizontal;
        vector<int> vertical;
        while (n--) {
            int x;
            int y;
            cin >> x >> y;
            horizontal.push_back(x);
            vertical.push_back(y);
        }
        cout << penalty(h, w, horizontal, vertical)<<endl;
    }
    
    return 0;
}
