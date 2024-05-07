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
    ListNode* rev(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        ListNode* h= rev(head);
        ListNode* hh= h;
        int carry = 0;
        ListNode* temp = new ListNode(-1),*dummy = temp;
        while(h || carry){
            int doublee = 0;
            if(h){
                doublee = 2*(h->val);
                h = h->next;
            }
            doublee += carry;
            carry = doublee/10;
            ListNode* x = new ListNode(doublee%10);
            temp->next = x;
            temp = x;
        }
        return rev(dummy->next);
    }
};