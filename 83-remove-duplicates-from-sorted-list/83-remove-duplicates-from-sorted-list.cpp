/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = head, *q = head->next;
        while(p and q){
            if(p->val==q->val){
                q = q->next;
            }
            else{
                p->next = q;
                p = p->next;
                q = q->next;
            }
            p->next = q;
            
        }
        return head;
    }
};