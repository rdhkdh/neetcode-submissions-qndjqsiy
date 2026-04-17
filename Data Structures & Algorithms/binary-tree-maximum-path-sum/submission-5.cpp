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

        int leftsum =  dfs(root->left);
        int rightsum = dfs(root->right); //avoid -ve sums

        int ans = root->val + max(leftsum, rightsum);
        return max(0, ans);
    }

    int maxPathSum(TreeNode* root) {

        if(root==NULL) {return 0;}

        //including current node
        int x = root->val + dfs(root->left) + dfs(root->right);

        //excluding current node
        int y1 = root->left ? maxPathSum(root->left) : INT_MIN;
        int y2 = root->right ? maxPathSum(root->right) : INT_MIN;

        return max(x, max(y1, y2));
    }
};
