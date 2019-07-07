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
private: 
    int tilit = 0;
public:
    int walk(TreeNode* root) {
        if (!root) return 0;
        int left = walk(root->left);
        int right = walk(root->right);
        tilit += abs(left - right);
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        walk(root);
        return tilit;
    }
};
