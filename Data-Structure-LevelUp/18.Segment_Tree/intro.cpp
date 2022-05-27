// In an array if particular segment sum is asked then in general:
// If N Query and N Updates then it take constant time for update and linear
// time for query If N Query and N Updates if maintained prefix sum  then it
// take constant time for query and linear time for update. Using segment tree
// it does both operation in logn time for both query & Update. It only take
// linear time to build tree .

#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int> arr, vector<int> &tree, int s, int e, int idx) {
    if (s == e) {
        tree[idx] = arr[s];
        return;
    }

    int mid = (s + e) / 2;

    buildTree(arr, tree, s, mid, 2 * idx);
    buildTree(arr, tree, mid + 1, e, 2 * idx + 1);

    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void updateTree(vector<int> &arr, vector<int> &tree, int s, int e, int idx,
                int updateIdx, int updateVal) {
    if (s == e) {
        arr[updateIdx] = updateVal;
        tree[idx] = updateVal;
        return;
    }

    int mid = (s + e) / 2;
    if (idx > mid) {
        updateTree(arr, tree, mid + 1, e, 2 * idx + 1, updateIdx, updateVal);
    } else {
        updateTree(arr, tree, s, mid, 2 * idx, updateIdx, updateVal);
    }

    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int query(vector<int> tree, int s, int e, int idx, int left, int right) {
    // Completely Outside range.
    if (s > right or e < left) {
        return 0;
    }

    // Completely Inside range.
    if (s >= left and e <= right) {
        return tree[idx];
    }

    // Partially Inside Partially Outside range.
    int mid = (s + e) / 2;
    int ans1 = query(tree, s, mid, 2 * idx, left, right);
    int ans2 = query(tree, mid + 1, e, 2 * idx + 1, left, right);
    return ans1 + ans2;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> tree(2 * arr.size());
    buildTree(arr, tree, 0, 8, 1);
    updateTree(arr, tree, 0, 8, 1, 2, 10);
    // Print the Buid tree.

    for (int i = 1; i < 2 * arr.size(); i++) {
        cout << tree[i] << ",";
    }
    cout << endl;
    cout << query(tree, 0, 8, 1, 2, 4);
}