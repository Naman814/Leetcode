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
    
    int findlen(ListNode* head){
        if(!head) return 0;
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=findlen(head);
        if(len==1){
            return NULL;
        }
        int counter=(len-n);
        if(counter==0){
            head=head->next;
            return head;
        }
        ListNode* p=head,*q=NULL;
        while(counter){
            q=p;
            p=p->next;
            counter-=1;
        }
        q->next=p->next;
        p->next=NULL;
        return head;
    }
};