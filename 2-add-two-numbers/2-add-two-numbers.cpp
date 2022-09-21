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
        ListNode* temp = new ListNode(-1);
        ListNode* temp2 = temp;
        int carry = 0;
        while((l1 || l2) || carry){
            int sum =0;
            if(l1){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
        }
        return temp2->next;
    }
};