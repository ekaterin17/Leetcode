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
    int ans = 0;
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        ans += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
};
