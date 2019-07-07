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
    vector<int> inPostorder;
public:
    vector<int> postorder(Node* root) {
        if (!root) {
            return inPostorder;
        }
        
        for(auto u : root->children) {
            postorder(u);
        }
        inPostorder.push_back(root->val);
        return inPostorder;   
    }
};
