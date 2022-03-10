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
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 and !l2) return NULL;
        int carry=0;
        int sum=0;
        ListNode *head=NULL, *tail=NULL;
        while(l1 || l2){
            sum = carry;
            if(l1) {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum+=l2->val;
                l2 = l2->next;
                   }
            if(!head){
                head = new ListNode(sum%10);
                tail = head;
            }
            else{
                ListNode *temp = new ListNode(sum%10);
                tail->next = temp;
                tail = temp;
            }
            carry = sum/10;
        }
        if(carry){
            ListNode *temp = new  ListNode(1);
            tail->next = temp;
        }
        return head;
    }
};