/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> checker;
        dfs(root, k, checker);
        return checker[k-1];
    }

private:
    void dfs(TreeNode* root, int& k, vector<int>& checker) {
        if (root == nullptr) return;
        dfs(root->left, k, checker);
        checker.push_back(root->val);
        if (checker.size() == k) return;
        dfs(root->right, k, checker);
    }
};