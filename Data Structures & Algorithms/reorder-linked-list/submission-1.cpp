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

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* next= curr->next;
            curr->next = prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
       if(!head || !head->next) return;

       ListNode* slow= head;
       ListNode* fast= head;

       while(fast!= NULL && fast->next!= NULL){
        slow= slow->next;
        fast= fast->next->next;
       }

       ListNode* second = reverse(slow->next);
       slow->next = NULL;
       ListNode* first =head;

       while(second){
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next= second;
        second->next= temp1;

        first = temp1;
        second = temp2;
       }
    }
};
