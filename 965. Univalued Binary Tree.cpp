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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        int value = root->val;
        return isUnivalTreeDfs(root->left,value) && isUnivalTreeDfs(root->right,value);
    }
    
    bool isUnivalTreeDfs(TreeNode* root, const int value) {
        if (!root) {
            return true;
        }
        if (root->val != value) {
            return false;
        }
        
        return isUnivalTreeDfs(root->left,value) && isUnivalTreeDfs(root->right,value);
    }
};
