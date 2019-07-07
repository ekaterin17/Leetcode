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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int left = getHeight(root->left) + 1;
        int right = getHeight(root->right) + 1;
        return max(left, right);
    }
};
