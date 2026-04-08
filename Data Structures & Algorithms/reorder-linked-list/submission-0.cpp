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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL) {return head;}

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* succ;

        while(curr!=NULL)
        {
            succ = curr->next;
            curr->next = prev;

            prev = curr;
            curr = succ;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* curr = head;

        //get value of n
        while(curr)
        {
            n++;
            curr = curr->next;
        }

        if(n<=2) {return;}

        //break linkedlist into 2 parts
        ListNode* l1;
        ListNode* l2;
        curr = head;
        int count = -1;
        while(curr)
        {
            count++;
            if(count == n/2) 
            {
                l2 = curr->next;
                l1 = head;
                curr->next = NULL;
                break;
            }

            curr = curr->next;
        }

        //reverse l2
        l2 = reverse(l2);

        //merge l1 and l2 alternately
        ListNode dummy(0);
        ListNode* tail = &dummy;


        while(l1 && l2)
        {
            // take from l1
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;

            // take from l2
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }

        // attach remaining (only l1 will remain in this problem)
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
    }
};
