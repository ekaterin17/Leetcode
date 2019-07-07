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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode* > q;
        q.push(root);
        int size = 1;
        while (!q.empty()) {
            int newSize = 0;
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (i+1 == size) res.push_back(node->val);
                if (node->left) {
                    newSize += 1;
                    q.push(node->left);
                }
                if (node->right) {
                    newSize += 1;
                    q.push(node->right);
                }
            }
            size = newSize;
        }
        return res;
        
    }
};
