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
    map<int, vector<TreeNode*>> allPossibleFBTs;
    vector<TreeNode*> allPossibleFBT(int N) {
        if (allPossibleFBTs[N].size() != 0) return allPossibleFBTs[N];
        vector<TreeNode*> res;
        if (N == 1) {
            res.push_back(new TreeNode(0));
        }
        if (N % 2) {
            for (int i = 1; i < N; ++i) {
                int leftCntNodes = i;
                int rightCntNodes = N-i-1;
                vector<TreeNode*> leftAllPossibleFBT = allPossibleFBT(leftCntNodes);
                vector<TreeNode*> rightAllPossibleFBT = allPossibleFBT(rightCntNodes);
                for (auto left:leftAllPossibleFBT) {
                    for (auto right:rightAllPossibleFBT) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
                }
            }
            
        }
        allPossibleFBTs[N] = res;
        return res;
    }
};
