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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        dfs(root1,leaves1);
        vector<int> leaves2;
        dfs(root2,leaves2);
        return leaves1 == leaves2;
    }
    
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
        }
        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
};
