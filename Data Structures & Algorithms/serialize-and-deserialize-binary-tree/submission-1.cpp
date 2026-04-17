/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    string bfs(TreeNode* root)
    {
        string res = "";
        if(root==NULL) {return res;}

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp==NULL)
            {
                res += "NULL#";
                continue;
            }

            res += to_string(temp->val);
            res += '#';

            q.push(temp->left);
            q.push(temp->right);
        }

        return res;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return bfs(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") {return NULL;}

        vector<string> v;
        string temp = "";
        for(auto u: data)
        {
            if(u=='#')
            {
                v.push_back(temp);
                temp = "";
            }
            else
            {
                temp += u;
            }
        }

        //process using queue
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(v[0]));
        q.push(root);
        int i = 1; //index for v

        while(!q.empty() && i<v.size())
        {
            TreeNode* curr = q.front();
            q.pop();

            //create left child
            if(v[i]!="NULL")
            {
                curr->left = new TreeNode(stoi(v[i]));
                q.push(curr->left);
            }
            i++;

            //create right child
            if(v[i]!="NULL")
            {
                curr->right = new TreeNode(stoi(v[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};
