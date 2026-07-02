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
        if(!head) return NULL;
        Node* result;

        Node* ptr=head;

        while(ptr){
           Node* ptr_next= ptr->next;
           Node* copy= new Node(ptr->val);

           ptr->next=copy;
           copy->next=ptr_next;
           ptr=ptr_next;
        }
        ptr=head;
        result=head->next;

        while(ptr){
            Node* copy= ptr->next;
            Node* ptr_next= copy->next;

            if(ptr->random) copy->random=ptr->random->next;
            else copy->random=NULL;

            ptr=ptr_next;
        }
        ptr=head;

        while(ptr){
            Node* copy= ptr->next;
            Node* ptr_next= copy->next;

            ptr->next=ptr_next;
            if(ptr->next) copy->next=ptr_next->next;
            ptr=ptr->next;
        }
        return result;
    }
};