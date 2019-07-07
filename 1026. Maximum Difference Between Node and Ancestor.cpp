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
    int findMaxDif(TreeNode* root, int maxVal, int minVal) {
        if (root == NULL) return maxVal-minVal;
        int left = findMaxDif(root->left, max(maxVal, root->val), min(minVal, root->val));
        int right = findMaxDif(root->right, max(maxVal, root->val), min(minVal, root->val));
        return left>right ? left:right;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDif(root, root->val,root->val);
    }
};
