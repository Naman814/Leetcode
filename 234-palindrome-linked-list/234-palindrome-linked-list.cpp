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
    
    ListNode* getmiddle(ListNode* p){
        if(!p) return NULL;
        ListNode* s=new ListNode(0), *f=new ListNode(0);
        s->next=p;
        f->next=p;
        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    
    ListNode* reverseList(ListNode* p){
        if(!p) return NULL;
        ListNode* prev=NULL, *curr=p, *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=NULL;
        mid=getmiddle(head);
        mid->next=reverseList(mid->next);
        ListNode *start=head , *q=mid->next;
        while(q and start->val==q->val){
            start=start->next;
            q=q->next;
        }
        
       // mid->next=reverseList(mid->next);
        if(q==NULL){
            return 1;
        }
        return 0;
        
    }
};