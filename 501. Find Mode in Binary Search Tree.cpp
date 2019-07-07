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
    vector<int> findMode(TreeNode* root) {
        map<int,int> frequencies;
        findFrequency(root, frequencies);
        vector<int> res;
        int max = 0;
        for (auto el : frequencies) {
            if (el.second > max) {
                res.clear();
                max = el.second;
                res.push_back(el.first);
            } else if (el.second == max) {
                res.push_back(el.first);
            }
        }
        return res;
    }
    
    void findFrequency(TreeNode* root, map<int,int>& f) {
        if (!root) return;
        f[root->val] += 1;
        findFrequency(root->right, f);
        findFrequency(root->left, f);
    }
};
