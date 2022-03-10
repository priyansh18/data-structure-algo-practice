#include <bits/stdc++.h>
using namespace std;

// Dfs without using extra space

const int N = 1e5;
int par[N];
vector<int> graph[N]; 

void dfs(int root,int parent) {
    par[root] = parent;
    for (auto x : graph[root]) {
        if (x != parent) {
            // It Must be a child
            dfs(x,root);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, e;

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1,0);

    int x = 5;

    while (x!=0)
    {   
        cout<<x<<",";
        x = par[x];
    }
    

    return 0;
}