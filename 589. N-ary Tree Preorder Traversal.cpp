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
private:
    vector<int> inPreoder;
public:
    vector<int> preorder(Node* root) {
        if (!root) {
            return inPreoder;
        }
        
        inPreoder.push_back(root->val);
        for (auto u : root->children) {
            preorder(u);
        }
        return inPreoder;
    }
};
