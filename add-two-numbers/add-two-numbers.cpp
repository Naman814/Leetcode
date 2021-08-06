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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0,sum=0;
        ListNode *head=NULL,*last=NULL;
        while(l1 || l2){
            sum=carry;
            if(l1){
                sum+=(l1->val);
                l1=l1->next;
            }
            
            if(l2){
                sum+=(l2->val);
                l2=l2->next;
            }
            
            int rem=sum%10;
            
            if(!head){
            head=new ListNode;
                head->val=rem;
                head->next=NULL;
                last=head;
            }
            else{
                ListNode *temp=new ListNode;
                temp->val=rem;
                temp->next=NULL;
                last->next=temp;
                last=temp;
            }
            
            carry=sum/10;
        }
        if(carry){
            ListNode *temp=new ListNode;
            temp->val=carry;
            last->next=temp;
            last=temp;
        }
        
        return head;
        
    }
};