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
    int maxPath(TreeNode* root, int& max) {
        if (!root) {
            return 0;
        }
        
        int left_max = maxPath(root->left, max);
        int right_max = maxPath(root->right, max);
        
        int sum = root->val;
        if (left_max > 0) {
            sum += left_max;
        }
        if (right_max > 0) {
            sum += right_max;
        }
        
        if (max < sum) {
            max = sum;
        }
        
        if (right_max > left_max && right_max > 0) {
            return right_max + root->val;
        } else if (left_max > 0) {
            return left_max + root->val;
        } else {
            return root->val;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        maxPath(root, ans);
        return ans;
    }
};
