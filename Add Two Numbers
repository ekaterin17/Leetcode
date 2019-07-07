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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode((l1->val + l2->val) % 10);
        long long transfer = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode *tail = head;
        
        while (l1 != NULL && l2 != NULL) {
            ListNode *newTail = new ListNode((l1->val + l2->val + transfer) % 10);
            tail->next = newTail;
            transfer = (l1->val + l2->val + transfer) / 10;
            l1 = l1->next;
            l2 = l2->next;
            tail = newTail;
        }
        
        if (l1 != NULL && l2 == NULL) {
            while (l1 != NULL) {
                ListNode *newTail = new ListNode((l1->val + transfer) % 10);
                tail->next = newTail;
                transfer = (l1->val + transfer) / 10;
                l1 = l1->next;
                tail = newTail;
             }
         }
        
         if (l1 == NULL && l2 != NULL) {
            while (l2 != NULL) {
                ListNode *newTail = new ListNode((l2->val + transfer) % 10);
                tail->next = newTail;
                transfer = (l2->val + transfer) / 10;
                l2 = l2->next;
                tail = newTail;
             }
         }
        
        while (transfer != 0) {
            ListNode *newTail = new ListNode(transfer % 10);
            tail->next = newTail;
            transfer = transfer / 10;
            tail = newTail;
        }

        return head;
    }
};
