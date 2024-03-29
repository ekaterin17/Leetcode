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
    int ans = 1;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans-1;
    }
    
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
};
