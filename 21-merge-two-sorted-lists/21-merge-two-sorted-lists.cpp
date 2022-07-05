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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            }
            else{
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
        }
        if(l1) dummy->next = l1;
        else dummy->next = l2;
        return res->next;
    }
};