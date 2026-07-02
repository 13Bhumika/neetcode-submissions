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
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* curr= head;
        ListNode* prev= NULL;

        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
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
        ListNode* temp=head;
        ListNode* prevLast= NULL;

        while(temp!=NULL){
            ListNode* kthNode= getkthNode(temp, k);
            
            if(kthNode== NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode* nextNode= kthNode->next;
            kthNode->next=NULL;
            reverseList(temp);
            
            if(temp==head) head=kthNode;
            else prevLast->next=kthNode;

            prevLast= temp;
            temp=nextNode;
        }
        return head;
    }
};