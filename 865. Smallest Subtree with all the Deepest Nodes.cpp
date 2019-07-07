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
    pair<TreeNode*, int> depth;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return maxDepthNode(root).first;
    }
    
    pair<TreeNode*, int> maxDepthNode(TreeNode* node) {
        if (!node) return {NULL,0};
        pair<TreeNode*, int> left = maxDepthNode(node->left);
        pair<TreeNode*, int> right = maxDepthNode(node->right);
        if (left.second == right.second) {
            return {node, left.second + 1};
        } else if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else {
            return {right.first, right.second + 1};
        }
    }
};
