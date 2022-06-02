// Network Delay Time.

#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;
    list<pair<int, int>>* l;

    Graph(int v) {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int dist) { l[u].push_back({v, dist}); }

    void printList() {
        for (int i = 0; i < V - 1; i++) {
            cout << "i : " << i + 1 << " ----> ";
            for (auto x : l[i + 1]) {
                cout << x.first << " and " << x.second << ",";
            }
            cout << endl;
        }
    }

    int networkDelayTime(int k, int n) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;
        // Initialize source distance to zero.
        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty()) {
            auto it = st.begin();
            int dstTillNow = it->first;
            int vertex = it->second;
            st.erase(it);

            for (auto nbr : l[vertex]) {
                int currentdst = nbr.second;
                int currentVertex = nbr.first;

                if (currentdst + dstTillNow < dist[currentVertex]) {
                    // Remove if nbr already exists inside set
                    auto f = st.find({dist[currentVertex], currentVertex});

                    if (f != st.end()) {
                        st.erase(f);
                    }

                    dist[currentVertex] = currentdst + dstTillNow;
                    st.insert({dist[currentVertex], currentVertex});
                }
            }
        }

        int maxVal = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            maxVal = max(maxVal, dist[i]);
        }

        return maxVal == INT_MAX ? -1 : maxVal;
    }
};

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n + 1);
        for (auto x : times) {
            g.addEdge(x[0], x[1], x[2]);
        }

        g.printList();

        return g.networkDelayTime(k, n);
    }
};

int main() {
    Solution s;
    vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
    int n = 2;
    int k = 2;
    cout << s.networkDelayTime(times, n, k);
}