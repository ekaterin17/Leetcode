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
    int longestUnivaluePath(TreeNode* root) {
        arrowLength(root);
        return ans;
    }
    
    int arrowLength(TreeNode* node) {
        if (!node) return 0;
        int left = arrowLength(node->left);
        int right = arrowLength(node->right);
        int arrowLeft = 0, arrowRight = 0;
        if (node->left && node->left->val == node->val) {
            arrowLeft += left + 1;
        }
        if (node->right && node->right->val == node->val) {
            arrowRight += right + 1;
        }
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
    
};
