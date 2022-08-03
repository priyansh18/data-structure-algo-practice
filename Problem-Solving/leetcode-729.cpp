// My Calendar I

#include <bits/stdc++.h>
using namespace std;

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int getMinimumTrips(vector<int> weights) {
    map<int, int> m;
    for (auto x : weights) {
        m[x]++;
    }

    int ans = 0;
    for (auto x : m) {
        if (x.second == 1) return -1;
        ans += ceil(x.second / 3.0);
    }

    return ans;
}

int main() {
    vector<int> weights = {1, 8, 5, 8, 5, 1, 1};
    cout << getMinimumTrips(weights);

    weights = {3,4,4,3, 1};
    cout << getMinimumTrips(weights);
}