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
    //int count = 0; 

    int dfs(TreeNode* root, int maxval)
    {
        if(root==NULL) {return 0;}

        int extra = root->val >= maxval ? 1 : 0;
        int leftgood = root->left ? dfs(root->left, max(maxval, root->left->val)) : 0;
        int rightgood = root->right ? dfs(root->right, max(maxval, root->right->val)) : 0;

        // if(root->left!=NULL)
        // {
        //     maxval = max(maxval, root->left->val);
        //     dfs(root->left, maxval);
        // }
        // if(root->right!=NULL)
        // {
        //     maxval = max(maxval, root->right->val);
        //     dfs(root->right, maxval);
        // }

        return extra + leftgood + rightgood;
    }

    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;

        return dfs(root, root->val);
    }
};
