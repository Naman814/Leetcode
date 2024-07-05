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

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        ListNode *prev=NULL,*curr=head,*next=NULL;
        int count = 0;
        while(curr){
            count++;
            next = curr->next;
            if(prev && next){
                if((prev->val<curr->val && next->val<curr->val) || (prev->val>curr->val && next->val>curr->val)){
                    res.push_back(count);
                }
            }
            prev = curr;
            curr = curr->next;
        }
        int minDistance = INT_MAX;
        int n = res.size();
        for(int i=1;i<n;++i){
            minDistance = min(minDistance,res[i] - res[i-1]);
        }
        if(n<2) return {-1,-1};
        return {minDistance,(res[n-1]-res[0])};

    }
};