/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp; //old node, new node
    unordered_set<Node*> visited; //set of visited nodes in old graph

    void dfs(Node* node)
    {
        visited.insert(node);

        for(auto u: node->neighbors)
        {
            //create neighbor if not created yet
            if(mp.find(u) == mp.end())
            {
                Node* temp = new Node(u->val);
                mp[u] = temp;
            }

            //connect neighbor
            mp[node]->neighbors.push_back(mp[u]);

            //if not visited, do dfs
            if(visited.find(u) == visited.end()) 
            { 
                dfs(u);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) {return NULL;}

        Node* new_node = new Node(node->val);
        mp[node] = new_node;

        dfs(node);

        return new_node;
    }
};
