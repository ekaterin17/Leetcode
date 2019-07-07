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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        if (root) {
            if (L <= root->val && root->val <= R) {
                ans += root->val;
                ans += rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
            }
            if (root->val < L) {
                ans += rangeSumBST(root->right, L, R);
            }
            if (root->val > R) {
                ans += rangeSumBST(root->left, L, R);
            }
        }
        return ans;
    }
};
