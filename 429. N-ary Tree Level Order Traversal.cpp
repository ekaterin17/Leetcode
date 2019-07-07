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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        if (root == NULL) {
            return levels;
        }
        
        queue<Node*> queueBFS;
        queueBFS.push(root);
        while (!queueBFS.empty()) {
            vector<int> level;
            size_t sizeQueueBFS = queueBFS.size();
            for (size_t i = 0; i < sizeQueueBFS; ++i) {
                Node* node = queueBFS.front();
                queueBFS.pop();
                level.push_back(node->val);
                for (auto elem : node->children) {
                    queueBFS.push(elem);
                }
            }
            levels.push_back(level);
        }
        
        return levels;
    }
};
