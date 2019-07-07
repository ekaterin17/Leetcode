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
    void preorderTest(TreeNode* node, int target, int currentSum, int& numPaths) {
        currentSum += node->val;
        if (currentSum == target)  ++numPaths;
        if (node->left != nullptr)  this->preorderTest(node->left, target, currentSum, numPaths);
        if (node->right != nullptr) this->preorderTest(node->right, target, currentSum, numPaths);
    }

    void inorderTraverse(TreeNode* node, int target, int& numPaths) {
        if (node->left != nullptr)  this->inorderTraverse(node->left, target, numPaths);
        int currentSum = 0;
        this->preorderTest(node, target, currentSum, numPaths);
        if (node->right != nullptr)  this->inorderTraverse(node->right, target, numPaths);
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)    return 0;
        int numPaths = 0;
        this->inorderTraverse(root, sum, numPaths);
        return numPaths;
    }
};
