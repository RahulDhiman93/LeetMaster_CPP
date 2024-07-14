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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder, inorder, index, 0, inorder.size()-1);
    }
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if (i>j) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);

        int mid = 0;
        for(int i=0;i<inorder.size();++i) {
            if(root->val==inorder[i]) {
                mid = i;
                break;
            }
        }

        root->left = helper(preorder, inorder, index, i, mid-1);
        root->right = helper(preorder, inorder, index, mid+1, j);

        return root;
    }
};