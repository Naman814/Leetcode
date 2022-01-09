/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *p=head, *head2=new Node(0),*itr=NULL,*front=NULL,*dummy=NULL;
        while(p){
            Node* temp=new Node(p->val);
            temp->next=p->next;
            if(head2==NULL){
                head2=temp;
            }
            p->next=temp;
            p=p->next->next;
        }
        p=head;
        while(p){
            if(p->random!=NULL){
            p->next->random=p->random->next;
            }
            p=p->next->next;
        }
        p=head;
        dummy=new Node(0);
        Node* copy=dummy;
        while(p){
        front=p->next->next;
        copy->next=p->next;
        p->next=front;
        copy=copy->next;
        p=front;
        }
        
        return dummy->next;
        
    }
};