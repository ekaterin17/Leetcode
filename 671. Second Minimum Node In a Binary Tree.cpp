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
    int minEl;
    long long ans = LONG_MAX;
public:
    void dfs(TreeNode* root) {
        if (!root) return;
        if (minEl < root->val && root->val < ans) {
            ans = root->val;
        } else if (minEl == root->val) {
            dfs(root->left);
            dfs(root->right);
        }
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        minEl = root->val;
        dfs(root);
        return ans < LONG_MAX ? ans : -1;
    }
};
