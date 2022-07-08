#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int buyMaximumProducts(int n, int k, int price[]) {
        // Write your code here
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 1; i <= n; i++) {
            pq.push({price[i - 1], i});
        }
        int count = 0;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if (k - temp.second * temp.first >= 0) {
                k -= temp.second * temp.first;
                count += temp.second;
            } else {
                while (k - temp.first >= 0) {
                    k -= temp.first;
                    count++;
                }
                break;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    int n = 3;
    int k = 45;
    int price[] = {10, 7, 19};
    cout << s.buyMaximumProducts(n, k, price) << endl;
}