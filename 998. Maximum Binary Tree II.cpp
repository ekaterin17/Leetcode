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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* curPar = NULL;
        while (cur && cur->val > val) {
            curPar = cur;
            cur = cur->right;
        }
        
        TreeNode* node = new TreeNode(val);
        if (curPar != NULL) {
            curPar->right = node;
        } else {
            root = node;
        }
        node->left = cur;
        return root;
            
    }
};
