/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    TreeNode* root;
    vector<TreeNode*> tree;
public:
    CBTInserter(TreeNode* root) {   
        this->root = root;
        if (!root) return;
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            tree.push_back(node);
            if (node->left != NULL)  q.push(node->left);
            if (node->right != NULL)  q.push(node->right);
        }
    }
    
    int insert(const int v) {
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        int N = tree.size()-1;
        if (N % 2 == 1) {
            tree[(N-1)/2]->left = node;
        } else {
            tree[(N-1)/2]->right = node;
        }
        return tree[(N-1)/2]->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
