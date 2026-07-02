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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        else if(!l2) return l1;

        ListNode* ptr1 =l1;
        ListNode* ptr2= l2;
        ListNode* dummy= new ListNode(0);
        ListNode* ptr= dummy;

        int carry=0;

        while(ptr1 && ptr2){
            int sum=0;
            sum= ptr1->val + ptr2->val + carry;
            carry= sum/10;
            int digit= sum%10;

            ptr->next=new ListNode(digit);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            ptr=ptr->next;            
        }
        while(ptr1){
            int sum=0;
            sum= ptr1->val + carry;
            carry= sum/10;
            int digit= sum%10;

            ptr->next=new ListNode(digit);
            ptr1=ptr1->next;
            ptr=ptr->next;
        }
        while(ptr2){
            int sum=0;
            sum= ptr2->val + carry;
            carry= sum/10;
            int digit= sum%10;

            ptr->next=new ListNode(digit);
            ptr2=ptr2->next;
            ptr=ptr->next;
        }
        if(carry) {
            ptr->next= new ListNode(carry);
            ptr=ptr->next;
        }
        return dummy->next;
    }
};