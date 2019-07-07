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
    vector<vector<string>> printTree(TreeNode* root) {
		if (!root) return vector<vector<string>>({});
		int maxLevels = max(treeLevels(root->left), treeLevels(root->right)) + 1;
		int numColumns = pow(2, maxLevels) - 1;
		vector<string> temp(numColumns, "");
		vector<vector<string>> result(maxLevels, temp);
		helperFunction(root, result, 0, numColumns / 2, pow(2, maxLevels - 2));
		return result;
	}

    int treeLevels(TreeNode* root) {
        if (!root) return 0;
        int left = treeLevels(root->left);
        int right = treeLevels(root->right);
        return max(left, right) + 1;
    }

    void helperFunction(TreeNode* root, vector<vector<string>>& result, int level, int column, int offset) {
        if (!root) return;
        result[level][column] = to_string(root->val);
        helperFunction(root->left, result, level + 1, column - offset, offset / 2);
        helperFunction(root->right, result, level + 1, column + offset, offset / 2);
    }
};
