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
    ListNode* rev(ListNode* h){
        if(!h || !h->next) return h;
        ListNode* prev = NULL, *next = NULL;
        while(h){
            next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
    
        ListNode* nn = rev(head), *t = nn;
        
        while(t && t->next){
            if(t->val > t->next->val){
                t->next = t->next->next;
            }
            else{
                t = t->next;
            }
        }
        return rev(nn);
    }
};