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
    int preorder_index;

    TreeNode* solve(vector<int> preorder, vector<int> inorder, int inorder_start, int inorder_end)
    {
        if(inorder_start > inorder_end) {return NULL;}

        int rootval = preorder[preorder_index];
        preorder_index++;

        TreeNode* root = new TreeNode(rootval);

        int index;
        for(int i=inorder_start; i<=inorder_end; i++)
        {
            if(inorder[i]==rootval) {index=i; break;}
        }

        root->left = solve(preorder, inorder, inorder_start, index-1);
        root->right = solve(preorder, inorder, index+1, inorder_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_index= 0;
        int n = inorder.size();

        return solve(preorder, inorder, 0, n-1);
    }
};
