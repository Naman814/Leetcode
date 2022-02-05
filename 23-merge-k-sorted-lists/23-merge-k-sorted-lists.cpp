class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        if(a->val <= b->val){
            a->next = merge(a->next,b);
            return a;
        }
        else{
            b->next = merge(a,b->next);
            return b;
        }
    }
    
};