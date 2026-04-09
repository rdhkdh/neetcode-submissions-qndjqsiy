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
    map<TreeNode*, int> height; //node, height of subtree
    map<TreeNode*, bool> balanced;

    void dfs(TreeNode* root)
    {
        if(root==NULL) {return;}

        dfs(root->left);
        dfs(root->right);

        int leftHeight = root->left ? height[root->left] : 0;
        int rightHeight = root->right ? height[root->right] : 0;

        height[root] = max(leftHeight, rightHeight)+1;

        if(abs(leftHeight-rightHeight)<=1) {balanced[root] = true;}
        else{balanced[root]=false;}
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        
        bool ans = true;
        for(auto u: balanced)
        {
            ans = ans && u.second;
        }

        return ans;
    }
};
