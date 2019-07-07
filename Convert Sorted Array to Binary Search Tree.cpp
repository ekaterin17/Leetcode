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
    TreeNode* createBST(const vector<int>& nums, int L, int R) {
        int mid = (L+R)/2;
        
        TreeNode* node = new TreeNode(nums[mid]);
        
        if (L<=mid-1)    node->left = this->createBST(nums, L, mid-1);
        if (mid+1<=R)    node->right = this->createBST(nums, mid+1, R);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)   return nullptr;
        TreeNode* root = this->createBST(nums, 0, nums.size()-1);
        return root;
    }
};
