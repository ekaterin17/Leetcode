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
    TreeNode* trimBST(const TreeNode* root, const int L, const int R) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        TreeNode* node = new TreeNode(root->val);
        node->left = trimBST(root->left,L,R);
        node->right = trimBST(root->right,L,R);
        return node;
    }
};
