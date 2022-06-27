// Cheapest Flights within k stops

#include <bits/stdc++.h>
using namespace std;

class qClass {
   public:
    int dist;
    int y;
    int stops;

    qClass(int x, int y, int z) {
        this->dist = x;
        this->y = y;
        this->stops = z;
    }
};

class Compare {
   public:
    bool operator()(qClass A, qClass B) { return A.dist > B.dist; }
};

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> v(n);
        for (auto x : flights) {
            v[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<qClass, vector<qClass>, Compare> minHeap;
        minHeap.push(qClass(0, src, 0));
        while (!minHeap.empty()) {
            auto temp = minHeap.top();
            minHeap.pop();
            if (temp.y == dst) return temp.dist;
            if (temp.stops <= k) {
                for (auto nbr : v[temp.y]) {
                    minHeap.push(qClass(temp.dist + nbr.second, nbr.first,
                                 temp.stops + 1));
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

    int src = 0;
    int dest = 3;
    int k = 1;
    cout << s.findCheapestPrice(n, flights, src, dest, k);
}
