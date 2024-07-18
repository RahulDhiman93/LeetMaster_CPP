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
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int res = root->val;
        int dummy = dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, int& res) {
        if(root == NULL) return 0;

        int lm = dfs(root->left, res);
        int rm = dfs(root->right, res);
        lm = max(lm, 0);
        rm = max(rm, 0);

        res = max(res, root->val+lm+rm);
        return root->val + max(lm, rm);
    }
};