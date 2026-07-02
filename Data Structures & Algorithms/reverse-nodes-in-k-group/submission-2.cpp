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
private: 
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* curr=head;
        ListNode* prev= NULL;

        while(curr){
            ListNode* next = curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }

    ListNode* getkthNode(ListNode* temp, int k){
        k-=1;

        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!= NULL){
            ListNode* kthNode = getkthNode(temp, k);

            if(kthNode == NULL){
                if(prev) prev->next= temp;
                break;
            }

            ListNode* next = kthNode->next;
            kthNode->next = NULL;

            reverse(temp);

            if(head == temp){
                head = kthNode;
            }
            else{ 
                prev->next=kthNode;     
            }      
            
            prev= temp;
            temp= next; 
        }
             
        return head;
    }
};
