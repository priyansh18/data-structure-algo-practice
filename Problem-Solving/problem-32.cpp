// Roads in berland

#include <bits/stdc++.h>
using namespace std;

class DSU {
   private:
    vector<int> parent, size, rank;

   public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        // path compression -> (log n)
        // path compression and size -> O(4 x alpha)
        return parent[node] = findPar(parent[node]);
    }

    void unionSize(int u, int v) {
        int s1 = findPar(u);
        int s2 = findPar(v);
        if (s1 != s2) {
            if (size[s1] < size[s2]) {
                parent[s1] = s2;
                size[s2] += size[s1];
            } else {
                parent[s2] = s1;
                size[s1] += size[s2];
            }
        }
    }

    void unionRank(int u, int v) {
        int s1 = findPar(u);
        int s2 = findPar(v);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s2] < rank[s1]) {
                parent[s2] = s1;
            }
            // rank is equal, in case of equal then increase
            else {
                parent[s1] = s2;
                rank[s2]++;
            }
        }
    }
};

void roadsInBerland() {
    int n, m;
    cin >> n;
    m = n - 1;
    DSU dsu(n + 1);
    vector<pair<int, int>> extraRoad;
    // step 1 storage of old roads is done
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (dsu.findPar(u) == dsu.findPar(v)) {
            extraRoad.push_back({u, v});
        } else {
            dsu.unionSize(u, v);
        }
    }

    // figure put the number of components -- nodes having same parent stored same parent inside parent array
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(dsu.findPar(i));
    }
    int x = st.size();

    vector<int> vec(st.begin(), st.end());
    int j = 0;
    for (int i = 1; i <= x - 1; i++) {
        cout << extraRoad[j].first << " " << extraRoad[j].second << " "
             << vec[i] << " " << vec[i - 1] << endl;
        j++;
    }
}

int main() { roadsInBerland(); }
