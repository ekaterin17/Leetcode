/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* cur;
    TreeNode* increasingBST(const TreeNode* root) {
        TreeNode* resTreeNode = new TreeNode(0);
        cur = resTreeNode;
        inOrder(root);
        return resTreeNode->right;     
    }
    
    void inOrder(const TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        TreeNode* node = new TreeNode(root->val);
        cur->right = node;
        cur = cur->right;
        inOrder(root->right);
    }
};
