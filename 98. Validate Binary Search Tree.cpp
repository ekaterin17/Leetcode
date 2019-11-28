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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        return isValid(root->left, NULL, root) && isValid(root->right, root, NULL);
    }
    
    bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) {
            return true;
        }
        
        if (min != NULL && root->val <= min->val || max != NULL && root->val >= max->val) {
            return false;
        }
        
        return isValid(root->left, min, root) && isValid(root->right, root, max);
    }
};
