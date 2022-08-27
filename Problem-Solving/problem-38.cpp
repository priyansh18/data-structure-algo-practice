// M-Colouring Problem

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    // Function to determine if graph can be coloured with at most M colours
    // such that no two adjacent vertices of graph are coloured with same
    // colour.
    bool canColor(int color, int node, vector<bool> &colorNode,
                  bool graph[101][101], int n) {
        if (int k = 0; k < n; k++) {
            if (k != node and graph[k][node] == 1 and colorNode[k] == color) {
                return false;
            }
        }
        return true;
    }

    bool canNodeColour(int m, int node, vector<bool> &colorNode,
                       bool graph[101][101], int n) {
        if (node == n) return true;
        for (int i = 1; i <= m; i++) {
            if (canColour(i, node, colorNode, graph, n)) {
                color[node] = i;
                if (canNodeColor(m, node + 1, colorNode, graph, n)) return true;
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<bool> colorNode(n, 0);
        return canNodeColour(m, 0, colorNode, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends