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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode * temphead = dummy;
        dummy->next = head;
        ListNode* f = dummy;
        for(int i=1;i<=n;i++){
            dummy = dummy->next;
        }
        while(dummy->next){
            f = f->next;
            dummy = dummy->next;
        }
        f->next = f->next->next;
        return temphead->next;
    }
};