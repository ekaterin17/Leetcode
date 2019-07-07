/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        int maxChildDepth = 0;
        for (size_t i = 0; i < root->children.size(); ++i) {
            int childDepth = maxDepth(root->children[i]);
            maxChildDepth = max(maxChildDepth, childDepth);
        }
        
        return maxChildDepth + 1;
    }
};
