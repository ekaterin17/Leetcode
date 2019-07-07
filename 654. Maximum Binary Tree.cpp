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
    int indexOfMax(vector<int>& nums, int left, int right) {
        int indMax = left;
        for (int i = left; i <= right; ++i) {
            if (nums[indMax] < nums[i]) indMax = i;
        }
        return indMax;
    }
    
    TreeNode* constructMaximumBinarySubtree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int maxIndex = indexOfMax(nums,left,right);
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = constructMaximumBinarySubtree(nums, left, maxIndex - 1);
        root->right = constructMaximumBinarySubtree(nums, maxIndex + 1, right);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        TreeNode* root = constructMaximumBinarySubtree(nums,0,nums.size()-1);
        return root;
    }
};
