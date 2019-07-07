/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct Item {
    int value;
    TreeNode* node;
  
    Item(TreeNode* _node, int _value): node(_node), value(_value) {};
} Item;

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        stack<Item> st;
        st.push(Item(root, 0));
        
        while (!st.empty()) {
            Item item = st.top();
            st.pop();
            
            TreeNode* node = item.node;
            int val = (item.value << 1) | node->val;
            
            if (!node->left && !node->right) {
                sum += val;
            }
            
            if (node->left) st.push(Item(node->left, val));
            if (node->right) st.push(Item(node->right, val));
            
        }
        
        return sum;
    }
};
