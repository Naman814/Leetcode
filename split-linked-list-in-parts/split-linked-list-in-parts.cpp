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
    int len(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int l=len(head);
        ListNode* p=NULL;
        if(l<=k){
           while(k){
               p=head?head:NULL;
               if(head) head=head->next;
               if(p) p->next=NULL;
               res.push_back(p);
               k--;
           }
            return res;
        }
        ListNode *cur2=head;
        for(int i=1;i<=k;i++)
        {
            if(i<=l%k)// for the first size%k nodes we need a linked list with an element one extra than the other ones
            {
                ListNode *tmp=cur2;int c=1;
                ListNode *cur1=cur2;
                while(c<(l/k)+1)
                {
                    cur1=cur1->next;
                    c++;
                }              
                cur2=cur1->next;
                cur1->next=nullptr;
                res.push_back(tmp);   
             }
            else
            {
                 ListNode *tmp=cur2;int c=1;      
                 ListNode *cur1=cur2;//for the other lined list
                while(c<l/k)
                {
                    cur1=cur1->next;
                    c++;
                }                
                 cur2=cur1->next;
                cur1->next=nullptr;
                res.push_back(tmp);   
            }
        }
        return res;
    }
};