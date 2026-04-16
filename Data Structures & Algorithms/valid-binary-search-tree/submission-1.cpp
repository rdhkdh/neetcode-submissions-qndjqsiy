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
    bool solve(TreeNode* root, int low, int high)
    {
        if(root==NULL) {return true;}
        if(root->val <= low || root->val >= high) {return false;}

        if(root->left && root->left->val >= root->val)
        {
            return false;
        }

        if(root->right && root->right->val <= root->val)
        {
            return false;
        }

        return solve(root->left, low, min(high, root->val)) &&
                solve(root->right, max(low, root->val), high);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
