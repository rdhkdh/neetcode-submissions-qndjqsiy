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
        if(head==NULL) {return NULL;}

        map<Node*, Node*> mp; //old, new node

        //create all nodes
        Node* curr = head; //curr in old list
        while(curr)
        {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            curr = curr->next;
        }

        //copy next and random pointers
        curr = head;
        while(curr)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};
