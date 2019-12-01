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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        size_t cur_count = 1;
        
        vector<int> leftNodes;
        int ans = root->val;
        while (!q.empty()) {
            leftNodes.push_back(q.front()->val);
            if (q.front()->left) {
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.push(q.front()->right);
            }
            q.pop();
            --cur_count;
            if (!cur_count) {
                cur_count = q.size();
                ans = leftNodes[0];
                leftNodes.clear();
            }
        }
        return ans;
    }
};
