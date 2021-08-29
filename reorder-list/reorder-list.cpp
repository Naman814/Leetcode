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
    
    ListNode* reverse(ListNode * head){
        ListNode * p=head,*q=NULL,*r=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    
    ListNode* middle(ListNode *head){
     ListNode* s=head,*f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    
    ListNode* merge(ListNode *p , ListNode *q){
        
        ListNode *tail=NULL;
        ListNode *head=p;
         ListNode *s=p;
        p=p->next;
        while(p && q){
           s->next=q;
           s=s->next;
           q=q->next;
           
           s->next=p;
           s=s->next;
           p=p->next;
        }
        if(p){
            s->next=p;
        }
        if(q){
            s->next=q;
        }        
        return head;    
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* mid=middle(head);
        ListNode *l1=head;
        ListNode *temp=mid->next;
        mid->next=NULL;
        ListNode* l2=reverse(temp);
        head=merge(l1,l2);
        
    }
};