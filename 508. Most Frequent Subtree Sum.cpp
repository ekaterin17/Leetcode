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
    map<int,int> sums;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        
        getAllTreeSum(root);
        map<int, vector<int>> frequentsTreeSum;
        for (auto it = sums.begin(); it != sums.end(); ++it) {
            frequentsTreeSum[it->second].push_back(it->first);
        }
      
        return frequentsTreeSum.rbegin()->second;
        
    }
    
    int getAllTreeSum(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + getAllTreeSum(root->left) + getAllTreeSum(root->right);
        sums[sum] += 1;
        return sum;
    }
};
