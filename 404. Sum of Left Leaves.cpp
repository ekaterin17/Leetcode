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
    void sums(TreeNode* root,int& sum) {
        if (root->left) sums(root->left,sum);
        if (root->left != NULL && root->left->right == NULL && root->left->left == NULL)
            sum += root->left->val;
        if (root->right) sums(root->right,sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right) return 0;
        int res = 0;
        sums(root, res);
        return res;
    }
};
