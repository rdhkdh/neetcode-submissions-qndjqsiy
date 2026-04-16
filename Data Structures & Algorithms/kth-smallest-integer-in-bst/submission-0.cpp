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

class Solution {
public:
    map<TreeNode*, int> nodes; //no of nodes in subtree rooted at node

    int dfs(TreeNode* root)
    {
        if(root==NULL) {return 0;}
        
        int leftn = dfs(root->left);
        int rightn = dfs(root->right);

        nodes[root] = 1 + leftn + rightn;

        return nodes[root];
    }

    int solve(TreeNode* root, int k)
    {
        int leftn = root->left ? nodes[root->left] : 0;

        if(leftn+1 < k) 
        {
            if(root->right==NULL) {return -1;}
            return solve(root->right, k-leftn-1);
        }
        else if(k == leftn+1) 
        {
            return root->val;
        }
        else if(k < leftn+1)
        {
            if(root->left==NULL) {return -1;}
            return solve(root->left, k);
        }

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return solve(root, k);
    }
};
