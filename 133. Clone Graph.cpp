/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node* > clones;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        if (clones.find(node) != clones.end()) {
            return clones[node];
        }
        
        clones[node] = new Node(node->val, {});

        for (Node* u : node->neighbors) {
            clones[node]->neighbors.emplace_back(cloneGraph(u));
        }
        
        return clones[node];
    }
};
