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
    int sumNodes = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        root->right = convertBST(root->right);
        sumNodes += root->val;
        root->val = sumNodes;
        root->left = convertBST(root->left);
        return root;
    }
};
