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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* curr = head;
        while(curr)
        {
            l++;
            curr = curr->next;
        }

        if(l==1) {return NULL;}
        if(n==l)
        {
            curr = head->next;
            head->next = NULL;
            return curr;
        }

        curr = head;
        int count = 0;
        while(curr)
        {
            count++;
            if(count == l-n)
            {
                ListNode* temp = curr->next;

                curr->next = temp->next;
                temp->next = NULL;
                break;
            }


            curr = curr->next;
        }

        return head;
    }
};
