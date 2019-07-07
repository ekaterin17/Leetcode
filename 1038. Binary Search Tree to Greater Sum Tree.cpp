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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        int a = dfs(root, sum);
        return root;
    }
    
    int dfs(TreeNode* root, int& sum) {
        if (!root) return 0;
        int right = dfs(root->right, sum);
        int a = root->val + right;
        root->val = a + sum;
        int left = dfs(root->left, root->val);
        return a + left;
    }
};
