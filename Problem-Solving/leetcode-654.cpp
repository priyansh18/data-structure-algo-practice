// Maximum Binary
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = right = NULL;
    }
};

void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        if (temp == NULL) {
            cout << endl;
            q.pop();
            // Insert New Null for next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return;
}

class Solution {
   public:
    pair<int, int> findMaxValue(vector<int> nums, int i, int j) {
        // Finding the max value.
        int maxVal = INT_MIN;
        int index = -1;
        for (int k = i; k <= j; k++) {
            if (nums[k] > maxVal) {
                maxVal = nums[k];
                index = k;
            }
        }

        return {index, maxVal};
    }

    TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int i,
                                               int j) {
        if (i > j) {
            return NULL;
        }
        pair<int, int> Vpair = findMaxValue(nums, i, j);
        TreeNode* head = new TreeNode(Vpair.second);
        head->left = constructMaximumBinaryTreeHelper(nums, i, Vpair.first-1);
        head->right = constructMaximumBinaryTreeHelper(nums, Vpair.first + 1, j);
        return head;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* newHead = constructMaximumBinaryTreeHelper(nums, 0, nums.size()-  1);
        return newHead;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode* result = s.constructMaximumBinaryTree(nums);
    printLevelOrder(result);
    cout << endl;
}