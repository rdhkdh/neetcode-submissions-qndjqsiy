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
    ListNode* reverseLinkedList(ListNode* head)
    {
        if(head==NULL) {return NULL;}

        ListNode* prev = NULL;

        while(head!=NULL)
        {
            ListNode* succ = head->next;
            
            head->next = prev;

            prev = head;
            head = succ;
        }

        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        vector<pair<ListNode*, ListNode*>> v; //head, tail

        ListNode* succ;
        ListNode* temp;
        ListNode* curr_head = head;
        while(head!=NULL)
        {
            count++;
            succ = head->next;

            if(count==k)
            {
                head->next = NULL;
                temp = reverseLinkedList(curr_head);
                v.push_back({temp, curr_head});

                curr_head = succ;
                count=0;
            }

            head = succ;
        }

        //join all the reversed lists
        int n = v.size();
        for(int i=1; i<n; i++)
        {
            v[i-1].second->next = v[i].first;
        }


        if(curr_head!=NULL)
        {
            v[n-1].second->next = curr_head;
        }

        if(v.empty()) {return head;}

        return v[0].first;
    }
};
