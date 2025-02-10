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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* head = root;
        helper(head);
        return head;
    }

private:
    void helper(TreeNode* node) {
        if(node == NULL) return;

        TreeNode* temp;
        temp = node->left;
        node->left = node->right;
        node->right = temp;

        helper(node->left);
        helper(node->right);    
    }
};