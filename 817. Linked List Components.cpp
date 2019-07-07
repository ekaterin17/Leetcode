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
    int numComponents(ListNode* head, const vector<int>& G) {
        set<int> Gset;
        for (auto a : G) {
            Gset.insert(a);
        }
        
        int cnt = 0;
        while (head != NULL) {
            if (Gset.count(head->val) && (head->next == NULL || !Gset.count(head->next->val)))
                ++cnt;
            head = head->next;
        }
        
        return cnt;
    }
};
