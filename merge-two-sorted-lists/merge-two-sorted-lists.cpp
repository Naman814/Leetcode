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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if(a==NULL) return b;
    if(b==NULL) return a;
     ListNode * head,*tail;
    if(a->val<=b->val){
        head=a;
        tail=a;
        a=a->next;
        tail->next=NULL;
    }
    else{
        head=b;
        tail=b;
        b=b->next;
        tail->next=NULL;
    }
    while(a && b){
        if(a->val<=b->val){
        tail->next=a;
            tail=a;
        a=a->next;
        tail->next=NULL;
    }
    else{
        tail->next=b;
        tail=b;
        b=b->next;
        tail->next=NULL;
    }
        
    }
    if(a){
        tail->next=a;
    }
    else{
        tail->next=b;
    }
    
    return head;
        
    }
};