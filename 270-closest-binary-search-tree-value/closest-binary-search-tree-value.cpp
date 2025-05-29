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
    int closestValue(TreeNode* root, double target) {
        if (root == nullptr) return 0;

        int res = root->val;
        dfs(root, target, res);
        return res;
    }

private:
    void dfs(TreeNode* root, double& target, int& res) {
        if (root == nullptr) return;

        if (abs((double)root->val - target) < abs((double)res - target)) {
            res = root->val;
        }

        if (abs((double)root->val - target) == abs((double)res - target)) {
            res = min(res, root->val);
        }

        if ((double)root->val > target)
            dfs(root->left, target, res);
        else
            dfs(root->right, target, res);
    }
};