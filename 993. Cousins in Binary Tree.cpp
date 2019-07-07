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
private:
    map<int, pair<int, TreeNode*>> nodes;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,0);
        return nodes[x].first == nodes[y].first && nodes[x].second != nodes[y].second;
    }
    
    void dfs(TreeNode* root, int x, int y, int depth) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            nodes[root->left->val] = pair(depth + 1, root);
            dfs(root->left,x,y,depth+1);
        }
        if (root->right != NULL) {
            nodes[root->right->val] = pair(depth + 1, root);
            dfs(root->right,x,y,depth+1);
        }
    }
};
