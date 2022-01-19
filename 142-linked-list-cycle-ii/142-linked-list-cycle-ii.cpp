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
    
  
    ListNode *detectCycle(ListNode *head) {
       
        int flag=0;
        ListNode* f=head, *s=head;
        while(s and f and f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) { flag=1; break; }
        }
        if(flag){
            s=head;
            while(s!=f){
                s=s->next;
                f=f->next;
            }
            return s;
        }
        return NULL;
        
    }
};