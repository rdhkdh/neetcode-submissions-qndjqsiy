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
    int maxDepth(TreeNode* root)
    {
        if(root==NULL) {return 0;}

        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) {return 0;}

        int temp1 = maxDepth(root->left) + maxDepth(root->right);
        int temp2 = diameterOfBinaryTree(root->left);
        int temp3 = diameterOfBinaryTree(root->right);

        return max(temp1, max(temp2, temp3));
    }
};
