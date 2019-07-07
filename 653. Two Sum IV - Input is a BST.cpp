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
    bool findTarget(TreeNode* root, int k) {
        set <int> nodesValue;
        queue<TreeNode*> qBFS;
        qBFS.push(root);
        while (!qBFS.empty()) {
            TreeNode* node = qBFS.front();
            qBFS.pop();
            if (nodesValue.find(k - node->val) != nodesValue.end()) {
                return true;
            }
            nodesValue.insert(node->val);
            if (node->left != NULL) {
                qBFS.push(node->left);
            }
            if (node->right != NULL) {
                qBFS.push(node->right);
            }
        }
        return false;
    }
};
