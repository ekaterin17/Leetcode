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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode* > listArray;
        ListNode* cur = head;
        while (cur != NULL) {
            listArray.push_back(cur);
            cur = cur->next;
        }
        return listArray[listArray.size() / 2];
    }
};
