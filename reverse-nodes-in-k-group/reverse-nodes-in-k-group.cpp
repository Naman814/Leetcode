class Solution {
public:
int length(ListNode * node){
    int count=0;
    while(node){
        count++;
        node=node->next;
    }
    return count;
}
ListNode* reverseKGroup(ListNode* head, int k) {
   if(length(head) < k)return head;
   ListNode * cur=head;
   ListNode * prev=NULL, *next=NULL;
   for(int i=0; i < k; i++){
       next=cur->next;
       cur->next=prev;
       prev=cur;
       cur=next;
   }
   head->next=reverseKGroup(cur, k);
   return prev;
 }
};