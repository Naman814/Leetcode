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
    ListNode* solve(ListNode* head){
        ListNode* s=head, *f=head;
        while(s && f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                return s;
            }
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* start=solve(head);
        if(start==NULL) return NULL;
        ListNode* s=head;
        while(s!=start){
            s=s->next;
            start=start->next;
        }
        return s;
    }
};