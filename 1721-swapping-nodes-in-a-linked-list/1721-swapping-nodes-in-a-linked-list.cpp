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
    int len(ListNode* p){
        int cnt=0;
        while(p){
            p=p->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int n = len(dummy);
        ListNode*p = dummy,*q=dummy;
        int temp = k;
        while(temp--){
            p = p->next;
        }
        temp = n-k;
        while(temp--){
            q = q->next;
        }
        temp = p->val;
        p->val = q->val;
        q->val = temp;
        return dummy->next;
    }
};