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
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int tmax, int& res) {
        if (root == NULL) return;
        if (root->val >= tmax) res++;
        dfs(root->left, max(root->val, tmax), res);
        dfs(root->right, max(root->val, tmax), res);
    }
};