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
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        while(curr1 && curr2)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        if(curr2) {return addTwoNumbers(l2, l1);}

        //l1 is the longer list
        int carry = 0;
        ListNode* head = l1;
        ListNode* prev = NULL;

        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            l1->val = sum%10;
            carry = sum/10;

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int sum = l1->val + carry;
            l1->val = sum%10;
            carry = sum/10;

            prev = l1;
            l1 = l1->next;
        }

        if(carry!=0)
        {
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }

        return head;
    }
};
