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
    //returning max sum path starting from root
    int dfs(TreeNode* root)
    {
        if(root==NULL) {return 0;}

        int leftmaxsum =  max(dfs(root->left), 0);
        int rightmaxsum = max(dfs(root->right), 0); //avoid -ve sums

        return root->val + max(leftmaxsum, rightmaxsum);
    }

    int maxPathSum(TreeNode* root) {

        if(root==NULL) {return 0;}

        //including current node
        int x = root->val + max(dfs(root->left),0) + max(dfs(root->right),0);

        //excluding current node
        int y1 = root->left ? maxPathSum(root->left) : INT_MIN;
        int y2 = root->right ? maxPathSum(root->right) : INT_MIN;

        return max(x, max(y1, y2));
    }
};
