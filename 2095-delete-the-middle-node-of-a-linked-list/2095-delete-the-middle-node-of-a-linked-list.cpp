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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        ListNode* prev=NULL , *s=head , *f=head;
        while(f and f->next){
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        if(!prev) return NULL;
        prev->next = prev->next->next;
        return head;
    }
};