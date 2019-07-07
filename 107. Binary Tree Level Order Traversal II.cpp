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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        
        if (!root) return res;
        
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            size_t size = q.size();
            vector<int> v;
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
