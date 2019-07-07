/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode* cur = root;
        while (cur != NULL) {
            n += 1;
            cur = cur->next;
        }
        
        int length = n / k;
        int rem = n % k;
        vector<ListNode*> result;
        for (int i = 0; i < k; ++i) {
            ListNode* head = new ListNode(0);
            ListNode* write = head;
            for (int j = 0; j < length + (i < rem ? 1 : 0); ++j) {
                write->next = new ListNode(root->val);
                write = write->next;
                if (root != NULL) root = root->next;
            }
            result.push_back(head->next);
        }
        
        return result;
    }
};
