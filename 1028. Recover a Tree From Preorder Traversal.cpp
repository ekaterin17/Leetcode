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
    TreeNode* recoverFromPreorder(string S) {
        stack<pair<TreeNode*,int> > st;
        TreeNode* root;
        int depth = 0;
        string num = "";
        S += "-";
        for (auto c : S) {
            if ('0' <= c && c <= '9') {
                num += c;
                continue;
            }
            if (c == '-' && num == "") {
                depth++;
                continue;
            }
            TreeNode* cur = new TreeNode(stoi(num));
            if (st.empty()) {
                st.push(make_pair(cur, 0));
                root = cur;
            } else {
                while (!st.empty()) {
                    auto pair = st.top();
                    if (pair.first->left && pair.first->right) {
                            st.pop();
                    } else if (pair.second == depth) {
                        st.pop();
                    } else if (pair.second + 1 == depth) {
                         if (pair.first->left) {
                            pair.first->right = cur;
                        } else {
                            pair.first->left = cur;
                        }
                        break;
                    } else {
                        st.pop();
                    }
                }
            }
            st.push(make_pair(cur, depth));
            num = "";
            depth = 1;
        }
        return root;
    }
};
