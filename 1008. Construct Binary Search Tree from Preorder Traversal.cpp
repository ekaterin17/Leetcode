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
    void AddNode(TreeNode* root, TreeNode* node) {
        if (root->val > node->val) {
            if (root->left == NULL) {
                root->left = node;
            } else {
                AddNode(root->left,node);
            }
        } else {
             if (root->right == NULL) {
                root->right = node;
            } else {
                AddNode(root->right,node);
            }
        }
    }
    
    TreeNode* bstFromPreorder(const vector<int>& preorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for (size_t i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            AddNode(root, node);
        }
        return root;
    }
};
