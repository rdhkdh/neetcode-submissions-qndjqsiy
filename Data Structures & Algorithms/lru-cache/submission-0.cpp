class Node { //doubly linked list
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) 
    {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp; //key, node of DLL
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int c) {
        this->capacity = c;

        head = new Node(0,0); //dummy head
        tail = new Node(0,0); //dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* curr)
    {
        Node* p = curr->prev;
        Node* s = curr->next;
        p->next = s;
        s->prev = p;
    }

    void insertAtTail(Node* node)
    {
        Node* p = tail->prev;
        Node* s = tail;
        node->prev = p;
        node->next = s;

        p->next = node;
        s->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) {return -1;}

        Node* node = mp[key];
        remove(node);
        insertAtTail(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) //key exists
        {
            Node* node = mp[key];
            remove(node);
            insertAtTail(node);
            node->val = value;
        }
        else //key does not exist
        {
            if(mp.size()==capacity)
            {
                Node* lru = head->next;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }

            Node* node = new Node(key, value);
            insertAtTail(node);
            mp[key] = node;
        }
    }
};
