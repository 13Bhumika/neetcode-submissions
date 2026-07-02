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

        ListNode* temp1= l1;
        ListNode* temp2= l2;

        int carry=0;
        int sum=0;
        int digit =0;

        ListNode* dummy = new ListNode(0);
        ListNode* ptr= dummy;

        while(temp1 && temp2){
            sum= temp1->val + temp2->val + carry;
            carry = sum/10;
            digit = sum%10;

            ptr->next = new ListNode(digit);
            temp1=temp1->next;
            temp2=temp2->next;
            ptr= ptr->next;
        }

        while(temp1){
            sum= temp1->val + carry;
            carry = sum/10;
            digit = sum%10;

            ptr->next= new ListNode(digit);
            temp1=temp1->next;
            ptr= ptr->next;
        }

        while(temp2){
            sum= temp2->val + carry;
            carry= sum/10;
            digit=sum%10;

            ptr->next = new ListNode(digit);
            temp2= temp2->next;
            ptr=ptr->next;
        }

        if(carry){
            ptr->next= new ListNode(carry);
            ptr= ptr->next;
        }
        return dummy->next;
    }
};
