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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        while (head) {
            ListNode* current = head->next;
            while (current && current->val <= head->val) current = current->next;
            if (current) {
                res.push_back(current->val);
            } else {
                res.push_back(0);
            }
            head = head->next;
        }
        return res;
    }
};
