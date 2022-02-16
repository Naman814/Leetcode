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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head , *newstart = p->next,*q=NULL, *temp=NULL;
        while(1){
             q = p->next;
             temp = q->next;
            q->next = p;
            if(!temp || !temp->next){
                p->next = temp;
                break;
            }
            p->next = temp->next;
            p = temp;
        }
        return newstart;
    }
};