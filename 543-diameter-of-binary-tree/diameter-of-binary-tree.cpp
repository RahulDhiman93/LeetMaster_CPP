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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int res = INT_MIN;
        updateRes(root, &res);
        return res;
    }

private:
    void updateRes(TreeNode* root, int* res) {
        if (root == NULL) return;
        *res = max(*res, (dfs(root->left) + dfs(root->right)));
        updateRes(root->left, res);
        updateRes(root->right, res);
    }

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(dfs(root->left), dfs(root->right));
    }
};