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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averageValueOnEachLevel;
        queue<TreeNode*> qBFS;
        qBFS.push(root);
        while (!qBFS.empty()) {
            size_t size = qBFS.size();
            long long sum = 0;
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = qBFS.front();
                qBFS.pop(); 
                sum += node->val;
                if (node->left != NULL) {
                    qBFS.push(node->left);
                }
                if (node->right != NULL) {
                    qBFS.push(node->right);
                }
            }
            averageValueOnEachLevel.push_back(((double) sum) / size);
        }
        return averageValueOnEachLevel;
    }
};
