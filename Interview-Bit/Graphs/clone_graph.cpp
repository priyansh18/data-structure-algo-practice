#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    if (node == NULL) return NULL;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label, {});
    m[node] = root;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        UndirectedGraphNode* newRoot = m[temp];

        for (auto nbr : newRoot->neighbors) {
            if (m[nbr]) {
                newRoot->neighbors.push_back(m[nbr]);
            } else {
                UndirectedGraphNode* new_nbr = new Node(nbr->val, {});
                q.push(nbr);
                v[nbr] = new_nbr;
                new_node->neighbors.push_back(new_nbr);
            }
        }
    }

    return m[node];
}

int main() {}