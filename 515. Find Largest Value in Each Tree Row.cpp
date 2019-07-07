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
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int>largestVal;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            int maxVal = INT_MIN;
            int childrenCount = 0;
            while (count > 0) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal,node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                    ++childrenCount;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    ++childrenCount;
                }
                --count;
            }
            count = childrenCount;
            largestVal.push_back(maxVal);
        }
        return largestVal;
    }
};
