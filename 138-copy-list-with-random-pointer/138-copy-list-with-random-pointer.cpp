class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* p=head, *q=NULL;
        while(p){
            Node* t=new Node(p->val);
            if(!q) q=t;
            t->next = p->next;
            p->next = t;
            p=p->next->next;
        }
        p=head;
        while(p){
            if(p->random){
            p->next->random =p->random->next;
            }
            p=p->next->next;
        }
        p = head;
        Node *front=NULL;
        Node *dummy = new Node(-1),*copy=dummy;
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