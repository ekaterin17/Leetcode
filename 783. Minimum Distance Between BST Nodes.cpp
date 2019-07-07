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
    void inorder(TreeNode* node, vector<int>& nums) {
        if (node->left) inorder(node->left, nums);
        nums.push_back(node->val);
        if (node->right) inorder(node->right, nums);
    }
    
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        vector<int> nums;
        inorder(root, nums);
        
        int sum = INT_MAX;
        for (size_t i = 0; i + 1 < nums.size(); ++i) {
            sum = min(sum, nums[i+1] - nums[i]);
        }
        return sum;
    }
};
