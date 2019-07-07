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
        size_t left = getLength(l1), right = getLength(l2), 
            max_size = std::max(left, right);
        
        ListNode dummyNode(0);
        ListNode *prev_nine = NULL, *cur = &dummyNode;
        for (size_t i = 0; i < max_size; ++i){
            int val = 0;
            if ((max_size - i) <= left){
                val += l1->val;
                l1 = l1->next;
            }
            
            if ((max_size - i) <= right){
                val += l2->val;
                l2 = l2->next;
            }
            
            if (val > 9){
                while (prev_nine != NULL && prev_nine != cur){
                    prev_nine->val =  (prev_nine->val + 1) % 10;
                    prev_nine = prev_nine->next;
                }
                
                cur->val = (cur->val + 1) % 10;
                prev_nine = (cur->val == 9) ? cur : NULL;
            }
            
            if (val % 10 == 9)
                prev_nine = prev_nine ? prev_nine : cur;
            else
                prev_nine = NULL;
            
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }
        
        ListNode* result = NULL;
        if (dummyNode.val != 0){
            result = new ListNode(dummyNode.val);
            result->next = dummyNode.next;
        }
        else
            result = dummyNode.next;
        return result;
    }

private:
    size_t getLength(ListNode* node){
        size_t res = 0;
        while(node){
            ++res;
            node = node->next;
        }
        return res;
    }
};
