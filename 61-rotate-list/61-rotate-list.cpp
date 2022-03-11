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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int len=1;
        ListNode* q=head;
        while(q->next){
            q = q->next;
            len++;
        }
        q->next=head;
        k = len-k%len;
        while(k--){
            q = q->next;
        }
        head=q->next;
        q->next=NULL;
        return head;
    }
};